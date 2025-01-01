#include "EuropeanDigitalCallOption.h"

// Constructor
EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff implementation for digital call
double EuropeanDigitalCallOption::payoff(double underlyingPrice) const {
    return (underlyingPrice >= _strike) ? 1.0 : 0.0;
}

// Get the type of the option (here DIGITAL_CALL)
EuropeanDigitalOption::digitalOptionType EuropeanDigitalCallOption::getDigitalOptionType() const
{
    return DIGITAL_CALL;
}