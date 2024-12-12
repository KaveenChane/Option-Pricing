#include "EuropeanDigitalCallOption.h"

// Constructor
EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff function: h(z) = 1 if z >= K, otherwise 0
double EuropeanDigitalCallOption::payoff(double underlyingPrice) const {
    return (underlyingPrice >= _strike) ? 1.0 : 0.0;
}

EuropeanDigitalOption::digitalOptionType EuropeanDigitalCallOption::getDigitalOptionType() const
{
    return DIGITAL_CALL;
}