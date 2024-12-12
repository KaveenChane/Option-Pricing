#pragma once
#ifndef OPTION_H
#define OPTION_H

#include<vector>

class Option {
private:
    double _expiry;

public:
    Option();
    Option(double);
    virtual ~Option() = default;

    double getExpiry() const;
    virtual double payoff(double) const = 0;
    virtual double payoffPath(std::vector<double>);

    virtual bool isAsianOption();
    virtual std::vector<double> getTimeStep() {
        return { 0 };
    };

};
#endif // OPTION_H