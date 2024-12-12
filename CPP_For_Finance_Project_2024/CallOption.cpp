#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {};

double CallOption::payoff(double z) const
{
	return std::max(0.0, z-getStrike());
}

EuropeanVanillaOption::optionType CallOption::getOptionType() const
{
	return CALL;
}