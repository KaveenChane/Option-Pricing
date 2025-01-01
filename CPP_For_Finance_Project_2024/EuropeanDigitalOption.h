#pragma once
#ifndef EUROPEAN_DIGITAL_OPTION_H
#define EUROPEAN_DIGITAL_OPTION_H

#include "Option.h"

class EuropeanDigitalOption : public Option {
protected:
    double _strike;

public:
    enum digitalOptionType { DIGITAL_CALL, DIGITAL_PUT };
    // Constructor
    EuropeanDigitalOption(double expiry, double strike);

    //getter
    double getStrike() const;

    // Virtual payoff method ( must be implemented in derived classes)
    virtual double payoff(double underlyingPrice) const override = 0;

    virtual digitalOptionType getDigitalOptionType() const = 0;

    // Virtual destructor
    virtual ~EuropeanDigitalOption() = default;
};

#endif
