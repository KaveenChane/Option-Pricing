#include "EuropeanDigitalPutOption.h"

// Constructor
EuropeanDigitalPutOption::EuropeanDigitalPutOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff function: h(z) = 1 if z <= K, otherwise 0
double EuropeanDigitalPutOption::payoff(double underlyingPrice) const {
    return (underlyingPrice <= _strike) ? 1.0 : 0.0;
}

EuropeanDigitalOption::digitalOptionType EuropeanDigitalPutOption::getDigitalOptionType() const
{
    return DIGITAL_PUT;
}