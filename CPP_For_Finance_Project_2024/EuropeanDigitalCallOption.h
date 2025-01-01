#pragma once
#ifndef EUROPEAN_DIGITAL_CALL_OPTION_H
#define EUROPEAN_DIGITAL_CALL_OPTION_H

#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    // Constructor
    EuropeanDigitalCallOption(double expiry, double strike);

    // Payoff implementation
    double payoff(double underlyingPrice) const override;

    digitalOptionType getDigitalOptionType() const override;

    ~EuropeanDigitalCallOption() = default;
};

#endif
