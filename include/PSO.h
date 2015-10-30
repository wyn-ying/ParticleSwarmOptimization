#ifndef PSO_H
#define PSO_H

#include "network.h"
#include "particle.h"
#include "parameters.h"
#include "randomNumGenerator.h"
#include "functions.h"
#include "performance.h"


void InitSwarm(networkMatrix,int);

void setPbest();

void setLbest();

void setGbest();

void UpdateSwarm();

performance RunPSO(networkMatrix,int);



#endif // PSO_H
