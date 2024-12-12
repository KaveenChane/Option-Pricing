#pragma once
#include "Option.h"
#include <vector>
#include <stdexcept>
#include <cmath>
#include "MT.h"

class BlackScholesMCPricer {
private:
    Option* option;               
    double initial_price;          
    double interest_rate;          
    double volatility;            
    int nbPaths;                  
    //double _currentEstimate;       
    //double _currentVariance; 
    double sum;
    double sumSquares;

public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);

    int getNbPaths();
    void generate(int nb_paths);       
    std::vector<double> confidenceInterval();
    double operator()();
};

