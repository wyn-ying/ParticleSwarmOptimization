#ifndef PARTICLE_H
#define PARTICLE_H

#include "parameters.h"
#include "network.h"


class particle
{
public:
	particle();
	virtual ~particle();

	int particleID;
	array<double,Dimension> position;
	array<double,Dimension> velocity;
	double fitness;
	array<double,Dimension> pbest;
	double fpbest;
	array<double,Dimension> lbest;
	double flbest;
	vector<int> neighborsID;

	//for partialFeedbackPSO
	vector<int> feedbackNeighborsID;

	//for FIPS
	array<double,Dimension> lbest_FIPS;

	int isFIPS;

	void reset();

protected:
private:

};

#endif // PARTICLE_H
