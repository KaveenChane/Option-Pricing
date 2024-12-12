#pragma once
#ifndef CALLOPTION_H
#define CALLOPTION_H

#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption {  // Héritage public
public:
    CallOption(double expiry, double strike);

    double payoff(double underlyingPrice) const override;
    optionType getOptionType() const override;
};

#endif // CALLOPTION_H
