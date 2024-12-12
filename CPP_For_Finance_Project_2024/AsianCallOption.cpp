#include "AsianCallOption.h"

AsianCallOption::AsianCallOption(std::vector<double> ts, double s) : AsianOption(ts), _strike{ s } {}

double AsianCallOption::payoff(double poP) const {
    return (poP >= _strike) ? (poP - _strike) : 0;
}
