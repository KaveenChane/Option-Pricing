#include "CRRPricer.h"
#include <cmath>
#include <stdexcept>

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
    : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate), _computed(false) {
    
    if (option->isAsianOption() == true) { 
        throw std::string("CRRPricer doesn't work with Asian options ! ");
    }
    
    if (!hasArbitrage()) {
        throw std::invalid_argument("Arbitrage condition not met. Check up, down, and interest rate values."); // le message d'erreur ne s'affiche pas, mais l'exception est bien prise en compte
    }
    _tree.setDepth(_depth); // Initialize the tree structure
}

double CRRPricer::riskNeutralProbability() const {
    return (_interest_rate - _down) / (_up - _down);
}
// Helper function to check for arbitrage
bool CRRPricer::hasArbitrage() const {
    return (_down < _interest_rate) && (_interest_rate < _up);
}


// 2nd constructor, overload of CRRPricer for american options

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility)
{
    //throw exception if it's an asian option
    if (option->isAsianOption() == true) {
        throw std::string("CRRPricer can not work with Asian options. Please try with another type of option");
    }

    double h = option->getExpiry() / depth;
    this->_up = exp((r + volatility * volatility / 2) * h + volatility * std::sqrt(h)) - 1;
    this->_down = exp((r + volatility * volatility / 2) * h - volatility * std::sqrt(h)) - 1;
    this->_interest_rate = exp(r * h) - 1;

    this->_option = option;
    this->_depth = depth;
    this->_asset_price = asset_price;

    if (_down >= _interest_rate || _interest_rate >= _up)
    {
        std::cout << "An arbitrage is detected";
        exit(-1);
    }
    _tree.setDepth(depth);
    exercise.setDepth(depth);
}

// Getter for H(n, i)
double CRRPricer::get(int n, int i) {
    return _tree.getNode(n, i);
}

double CRRPricer::StockPrice(int n, int i) {
    double S0 = get(0, 0);
    return S0 * std::pow(1 + _up, i) * std::pow(1 + _down, n - i);
}

void CRRPricer::compute() {
    _tree.setNode(0, 0, _asset_price);
    for (int i = 0; i <= _depth; i++) {
        double stockPrice = StockPrice(_depth, i);
        double payoff = _option->payoff(stockPrice);
        _tree.setNode(_depth, i, payoff);
    }

    if (_option->isAmericanOption())
    {
        for (int step = _depth - 1; step >= 0; step--) {
            for (int i = 0; i <= step; i++) {
                double upValue = _tree.getNode(step + 1, i + 1);
                double downValue = _tree.getNode(step + 1, i);
                double intrinsicValue = _option->payoff(StockPrice(step, i));
                double discountFactor = 1.0 / (1.0 + _interest_rate);

                double continuationValue = (riskNeutralProbability() * upValue + (1.0 - riskNeutralProbability()) * downValue) * discountFactor;

                bool shouldExercise = intrinsicValue >= continuationValue;
                exercise.setNode(step, i, shouldExercise);

                double expectedValue = shouldExercise ? intrinsicValue : continuationValue;
                _tree.setNode(step, i, expectedValue);
            }
        }
    }

    for (int step = _depth - 1; step >= 0; step--) {
        for (int i = 0; i <= step; i++) {
            double upValue = _tree.getNode(step + 1, i + 1);
            double downValue = _tree.getNode(step + 1, i);
            double discountFactor = 1.0 / (1.0 + _interest_rate);
            double expectedValue = (riskNeutralProbability() * upValue + (1.0 - riskNeutralProbability()) * downValue) * discountFactor;
            _tree.setNode(step, i, expectedValue);
        }
    }
}

double CRRPricer::binomialCoefficient(int n, int k) const {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    double res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - k + i) / static_cast<double>(i);
    }
    return res;
}

// Modification of the operator () to return the option price
double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        double up_factor = 1 + _up;
        double down_factor = 1 + _down;

        double q = riskNeutralProbability();
        double price = 0.0;

        for (int i = 0; i <= _depth; ++i) {
            double stockPriceUp = std::pow(up_factor, i);
            double stockPriceDown = std::pow(down_factor, _depth - i);
            double payoff = _option->payoff(_asset_price * stockPriceUp * stockPriceDown);
            double binomCoeff = binomialCoefficient(_depth, i);
            price += binomCoeff * std::pow(q, i) * std::pow(1 - q, _depth - i) * payoff;
        }

        price /= std::pow(1 + _interest_rate, _depth);
        return price;
    } else {
        //compute if not already done
        if (!_computed) compute();
        // Return the price at the root node
        return _tree.getNode(0, 0);
    }
}

bool CRRPricer::getExercise(int n, int i)
{
    return this->exercise.getNode(n, i);
}
