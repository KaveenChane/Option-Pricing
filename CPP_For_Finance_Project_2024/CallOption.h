#pragma once
#ifndef CALLOPTION_H
#define CALLOPTION_H

#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption
{
public:
    CallOption(double expiry, double strike);

    double payoff(double underlyingPrice) const override;
    optionType getOptionType() const override;
};

#endif
