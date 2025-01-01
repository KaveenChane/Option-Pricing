#pragma once
#ifndef EUROPEAN_DIGITAL_PUT_OPTION_H
#define EUROPEAN_DIGITAL_PUT_OPTION_H

#include "EuropeanDigitalOption.h"

class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    // Constructor
    EuropeanDigitalPutOption(double expiry, double strike);

    // Payoff implementation
    double payoff(double underlyingPrice) const override;

    digitalOptionType getDigitalOptionType() const override;

    ~EuropeanDigitalPutOption() = default;
};

#endif
