#include "BlackScholesMCPricer.h"
#include "AsianOption.h"
#include "MT.h"

// Constructor definition
BlackScholesMCPricer::BlackScholesMCPricer(Option* o, double ip, double ir, double v) : option(o), initial_price(ip), interest_rate(ir), volatility(v) {
    nbPaths = 0;
    sum = 0;
    sumSquares = 0;
};

int BlackScholesMCPricer::getNbPaths()
{ 
    return nbPaths;
};

//generation of paths
void BlackScholesMCPricer::generate(int Nb_paths) {
    double temp1 = interest_rate - (volatility * volatility) / 2;
    for (int k = 0; k < Nb_paths; k++)
    {
        std::vector<double> newPaths;
        if (option->isAsianOption())
        {
            newPaths.push_back(initial_price * exp(temp1 * option->getTimeStep()[0] + volatility * std::sqrt(option->getTimeStep()[0]) * MT::rand_norm()));
        }
        else
        {
            newPaths.push_back(initial_price * exp(temp1 * option->getExpiry() + volatility * std::sqrt(option->getExpiry()) * MT::rand_norm()));
        }
        for (int k = 1; k < option->getTimeStep().size(); k++) {
            newPaths.push_back(newPaths[k - 1] * exp(temp1 * (option->getTimeStep()[k] - option->getTimeStep()[k - 1]) + volatility * std::sqrt(option->getTimeStep()[k] - option->getTimeStep()[k - 1]) * MT::rand_norm()));
        }
        sum += option->payoffPath(newPaths);
    }
    nbPaths += Nb_paths;
};


double BlackScholesMCPricer::operator()() {
    return exp(-interest_rate * option->getExpiry()) * sum / nbPaths;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval() {
    double discount_factor = exp(-interest_rate * option->getExpiry());
    double mean = discount_factor * sum / nbPaths;

    double variance = (sumSquares / nbPaths) - (sum / nbPaths) * (sum / nbPaths);

    //ecart type
    double stddev = std::sqrt(variance);

    // Erreur à 95% (Z = 1.96 pour la loi normale)
    double margin_of_error = 1.96 * stddev / std::sqrt(nbPaths);

    // Calcul des bornes
    double lowerBound = mean - margin_of_error;
    double upperBound = mean + margin_of_error;

    return { lowerBound, upperBound };
}

