#include "BlackScholesPricer.h"
#include <cmath>

// Constructor
BlackScholesPricer::BlackScholesPricer(EuropeanVanillaOption* option, double assetPrice, double interestRate, double volatility)
    : _option(option), _assetPrice(assetPrice), _interestRate(interestRate), _volatility(volatility) {}

BlackScholesPricer::BlackScholesPricer(EuropeanDigitalOption* digitalOption, double assetPrice, double interestRate, double volatility)
    : _digitalOption(digitalOption), _assetPrice(assetPrice), _interestRate(interestRate), _volatility(volatility) {}


// Standard normal CDF
double BlackScholesPricer::normalCDF(double x) const {
    return 0.5 * std::erfc(-x * 1.0 / std::sqrt(2.0));
}

//option pricing
double BlackScholesPricer::operator()() const {
    if (_option != nullptr) {
        double strike = _option->_strike;
        double expiry = _option->getExpiry();
        double d1 = (std::log(_assetPrice / strike) + (_interestRate + 0.5 * _volatility * _volatility) * expiry) /
            (_volatility * std::sqrt(expiry));
        double d2 = d1 - _volatility * std::sqrt(expiry);

        if (_option->getOptionType() == EuropeanVanillaOption::CALL) {
            return _assetPrice * normalCDF(d1) - strike * std::exp(-_interestRate * expiry) * normalCDF(d2);
        }
        else { // PUT
            return strike * std::exp(-_interestRate * expiry) * normalCDF(-d2) - _assetPrice * normalCDF(-d1);
        }
    }
    else if (_digitalOption != nullptr) {
        double temp1 = (1 / (_volatility * std::sqrt(_digitalOption->getExpiry())));
        double temp2 = std::log(_assetPrice / _digitalOption->getStrike());
        double temp3 = _digitalOption->getExpiry() * (_interestRate - (_volatility * _volatility / 2));
        double d2 = temp1 * (temp2 + temp3);

        if (_digitalOption->getDigitalOptionType() == EuropeanDigitalOption::DIGITAL_CALL) {
            return exp(-_interestRate * _digitalOption->getExpiry()) * 0.5 * std::erfc(-d2 / std::sqrt(2));
        }
        else {
            return exp(-_interestRate * _digitalOption->getExpiry()) * 0.5 * std::erfc(d2 / std::sqrt(2));
        }
    }
    else
    {
        return 0;
    }
}

// Delta 
double BlackScholesPricer::delta() const {
    if (_option != nullptr)
    {
        double d1 = (std::log(_assetPrice / _option->_strike) +
            (_interestRate + 0.5 * _volatility * _volatility) * _option->getExpiry()) /
            (_volatility * std::sqrt(_option->getExpiry()));
        return (_option->getOptionType() == EuropeanVanillaOption::CALL) ? normalCDF(d1) : normalCDF(d1) - 1;
    }
    else if (_digitalOption != nullptr)
    {
        double temp1 = (1 / (_volatility * std::sqrt(_digitalOption->getExpiry())));
        double temp2 = std::log(_assetPrice / _digitalOption->getStrike());
        double temp3 = _digitalOption->getExpiry() * (_interestRate + (_volatility * _volatility / 2));
        double d1 = temp1 * (temp2 + temp3);

        if (_digitalOption->getDigitalOptionType() == EuropeanDigitalOption :: DIGITAL_CALL) {
            return 0.5 * std::erfc(-d1 / std::sqrt(2));
        }
        else {
            return 0.5 * std::erfc(-d1 / std::sqrt(2)) - 1.0;
        }
    }
    
}

/*
// Digital call option pricing
double BlackScholesPricer::price(const EuropeanDigitalCallOption& option) const {
    double strike = option.getStrike();
    double expiry = option.getExpiry();
    double d2 = (std::log(_assetPrice / strike) + (_interestRate - 0.5 * _volatility * _volatility) * expiry) /
                (_volatility * std::sqrt(expiry));

    return std::exp(-_interestRate * expiry) * normalCDF(d2);
}

// Digital put option pricing
double BlackScholesPricer::price(const EuropeanDigitalPutOption& option) const {
    double strike = option.getStrike();
    double expiry = option.getExpiry();
    double d2 = (std::log(_assetPrice / strike) + (_interestRate - 0.5 * _volatility * _volatility) * expiry) /
                (_volatility * std::sqrt(expiry));

    return std::exp(-_interestRate * expiry) * normalCDF(-d2);
}
*/
