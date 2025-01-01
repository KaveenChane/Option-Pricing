#include "PutOption.h"

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

// payoff implementation
double PutOption::payoff(double z) const {
    return std::max(0.0, getStrike() - z);
}

// get the type of this option (here PUT)
EuropeanVanillaOption::optionType PutOption::getOptionType() const {
    return PUT;
}