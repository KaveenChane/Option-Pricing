#pragma once
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption
{
public:
    AmericanCallOption(double& _expiry, double& _strike);
    double payoff(double) const override;
};