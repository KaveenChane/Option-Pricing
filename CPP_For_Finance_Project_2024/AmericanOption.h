#pragma once
#include "Option.h"

class AmericanOption : public Option
{
protected:
    double strike;
public:
    AmericanOption(double& expiry_arg, double& strike);
    bool isAmericanOption();
};


