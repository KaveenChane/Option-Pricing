#include "EuropeanDigitalPutOption.h"

// Constructor
EuropeanDigitalPutOption::EuropeanDigitalPutOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff implementation
double EuropeanDigitalPutOption::payoff(double underlyingPrice) const {
    return (underlyingPrice <= _strike) ? 1.0 : 0.0;
}

// Get the type of the option (here it's a DIGITAL_PUT)
EuropeanDigitalOption::digitalOptionType EuropeanDigitalPutOption::getDigitalOptionType() const
{
    return DIGITAL_PUT;
}