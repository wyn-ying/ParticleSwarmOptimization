#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include"parameters.h"
#include <array>

using std::array;


class performance
{
public:
	performance();
	virtual ~performance();

	double solution;
	array<double, MaxIteration / Interval + 1> solutions;
	int speed;
	int FIPSisGbest;
	int nonFIPSisGbest;
protected:
private:
};

#endif // PERFORMANCE_H
