#pragma once
#ifndef EUROPEAN_DIGITAL_CALL_OPTION_H
#define EUROPEAN_DIGITAL_CALL_OPTION_H

#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    // Constructor
    EuropeanDigitalCallOption(double expiry, double strike);

    // Implement payoff: h(z) = 1 if z >= K, otherwise 0
    double payoff(double underlyingPrice) const override;

    digitalOptionType getDigitalOptionType() const override;

    ~EuropeanDigitalCallOption() = default;
};

#endif // EUROPEAN_DIGITAL_CALL_OPTION_H
