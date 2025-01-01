#include "AmericanPutOption.h"

AmericanPutOption::AmericanPutOption(double& _expiry, double& _strike) : AmericanOption(_expiry, _strike) {}

//Payoff for American put
double AmericanPutOption::payoff(double p) const
{
	return (this->strike >= p) ? (this->strike - p) : 0;
}
