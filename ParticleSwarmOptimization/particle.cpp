#include "particle.h"

particle::particle()
{
	//ctor
	particleID=0;
	position.fill(0);
	velocity.fill(0);
	pbest.fill(0);
	lbest.fill(0);
	fitness=0;
	fpbest=0;
	flbest=0;
	neighborsID.clear();

	//for partialFeedbackPSO
	feedbackNeighborsID.clear();

	lbest_FIPS.fill(0);
}

particle::~particle()
{
	//dtor
}

void particle::reset()
{
	particleID=0;
	position.fill(0);
	velocity.fill(0);
	pbest.fill(0);
	lbest.fill(0);
	fitness=0;
	fpbest=0;
	flbest=0;
	neighborsID.clear();

	//for partialFeedbackPSO
	feedbackNeighborsID.clear();

	lbest_FIPS.fill(0);
}

