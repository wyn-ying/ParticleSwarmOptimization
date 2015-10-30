#include "particle.h"

particle::particle()
{
    //ctor
    particleID=0;
    position={};
    velocity={};
    pbest={};
    lbest={};
    fitness=0;
    fpbest=0;
    flbest=0;
    neighborsID.clear();
}

particle::~particle()
{
    //dtor
}

void particle::reset()
{
    particleID=0;
    position={};
    velocity={};
    pbest={};
    lbest={};
    fitness=0;
    fpbest=0;
    flbest=0;
    neighborsID.clear();
}


