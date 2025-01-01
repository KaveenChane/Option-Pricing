#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {};

// Payoff implementation
double CallOption::payoff(double z) const
{
	return std::max(0.0, z-getStrike());
}

// Get the type of the option (here it's a CALL)
EuropeanVanillaOption::optionType CallOption::getOptionType() const
{
	return CALL;
}