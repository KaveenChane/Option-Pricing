#include "AsianPutOption.h"

AsianPutOption::AsianPutOption(std::vector<double> ts, double s) : AsianOption(ts), _strike{ s } {}

// Payoff of asian put
double AsianPutOption::payoff(double averagePrice) const {
    return std::max(_strike - averagePrice, 0.0);
}