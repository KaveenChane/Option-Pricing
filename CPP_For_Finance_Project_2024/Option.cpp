#include <iostream>
#include "Option.h"

Option::Option() : _expiry{ 0 } {}

Option::Option(double e) {

	if (e > 0) {
		_expiry = e;
	}
	else {
		_expiry = 0;
		std::cout << "#error: expiry is negative" << std::endl;
	}
}
double Option::getExpiry() const {
    return _expiry;
}


double Option::payoffPath(std::vector<double> a) {
	return payoff(a.back());
}

bool Option::isAsianOption() {
	return false;
}