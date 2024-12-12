#pragma once
#include "AsianOption.h"

class AsianPutOption : public AsianOption {
protected:
	double _strike;
public:
	AsianPutOption(std::vector<double>, double);
	double payoff(double) const override;
};