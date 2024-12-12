#pragma once
#include "Option.h"

class AsianOption : public Option {
private:
	std::vector<double> _timeStep;
public:
	AsianOption(std::vector<double>);

	std::vector<double> getTimeStep();

	double payoffPath(std::vector<double>) override;
	
	bool isAsianOption() override;
};
