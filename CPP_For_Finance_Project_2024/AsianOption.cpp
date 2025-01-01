#include "AsianOption.h"

AsianOption::AsianOption(std::vector<double> ts) : Option(), _timeStep{ ts } {}

std::vector<double> AsianOption::getTimeStep()
{
	return _timeStep;
}

double AsianOption::payoffPath(std::vector<double> st)
{
	double stValue = 0;
	for (unsigned i = 0; i < st.size(); i++) stValue += st[i];
	return payoff(stValue / st.size());
}

bool AsianOption::isAsianOption()
{
	return true;
}