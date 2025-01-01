#pragma once
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption
{
public:
    AmericanPutOption(double& _expiry, double& _strike);
    double payoff(double) const override;
};

