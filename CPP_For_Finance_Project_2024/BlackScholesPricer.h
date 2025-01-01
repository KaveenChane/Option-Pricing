#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

#include "EuropeanVanillaOption.h"
#include "EuropeanDigitalOption.h"
#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"


class BlackScholesPricer {
private:
    EuropeanVanillaOption* _option; 
    EuropeanDigitalOption* _digitalOption;
    double _assetPrice;             
    double _interestRate;           
    double _volatility;             

    double normalCDF(double x) const; 

public:
    BlackScholesPricer(EuropeanVanillaOption*, double, double, double);
    
    BlackScholesPricer(EuropeanDigitalOption*, double, double, double);

    double operator()() const;
    double delta() const;

    double price(const EuropeanDigitalCallOption& option) const;
    double price(const EuropeanDigitalPutOption& option) const;
};

#endif