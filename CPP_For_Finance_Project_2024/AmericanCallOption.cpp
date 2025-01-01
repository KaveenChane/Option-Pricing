#include "AmericanCallOption.h"

AmericanCallOption::AmericanCallOption(double& _expiry, double& _strike) : AmericanOption(_expiry, _strike) {}

//payoff implementation
double AmericanCallOption::payoff(double p) const
{
	return (p >= this->strike) ? (p - this->strike) : 0;
}