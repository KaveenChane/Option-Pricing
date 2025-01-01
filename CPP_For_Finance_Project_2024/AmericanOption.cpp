#include<iostream>
#include "AmericanOption.h"

// Definition of american option

AmericanOption::AmericanOption(double& expiry, double& strike) : Option(expiry)
{
	if (strike > 0) {
		this->strike = strike;
	}
	else {
		this->strike = 0;
		std::cout << "Stike mustn't be negative !!" << std::endl;
	}
}

bool AmericanOption::isAmericanOption() {
	return true;
}
