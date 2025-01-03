#include <iostream>
#include "EuropeanDigitalOption.h"

// Constructor
EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike)
{
    if (expiry < 0 || strike < 0) {
        throw std::invalid_argument("Expiry and strike must be non-negative.");
    }
}

// Getter for the strike price
double EuropeanDigitalOption::getStrike() const {
    return _strike;
}
