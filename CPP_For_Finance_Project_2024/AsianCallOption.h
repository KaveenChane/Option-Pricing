#pragma once
#include "AsianOption.h"

class AsianCallOption : public AsianOption {
protected:
	double _strike;
public:
	AsianCallOption(std::vector<double>, double);
	double payoff(double) const override;
};