#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Option.h"
#include <stdexcept>


class EuropeanVanillaOption : public Option {
public:
    enum optionType { CALL, PUT };

private:
    double _strike;

public:
    friend class BlackScholesPricer;

    EuropeanVanillaOption(double, double);
    virtual optionType getOptionType() const = 0;
    double getStrike() const;
};


#endif