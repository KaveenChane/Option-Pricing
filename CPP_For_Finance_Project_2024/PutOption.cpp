#include "PutOption.h"

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

double PutOption::payoff(double z) const {
    return std::max(0.0, getStrike() - z);
}

EuropeanVanillaOption::optionType PutOption::getOptionType() const {
    return PUT;
}