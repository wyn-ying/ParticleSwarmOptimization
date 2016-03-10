#ifndef PSO_H
#define PSO_H

#include "network.h"
#include "particle.h"
#include "parameters.h"
#include "randomNumGenerator.h"
#include "functions.h"
#include "performance.h"

extern benchmarkFunc sphere;
extern benchmarkFunc rosenbrock;
extern benchmarkFunc rastrigin;
extern benchmarkFunc qua;
extern benchmarkFunc griwank;
extern benchmarkFunc ackley;
extern benchmarkFunc weierstrass;
extern benchmarkFunc noncontinuousRas;
extern benchmarkFunc schwefel_P2_22;
extern benchmarkFunc noise_1;
extern benchmarkFunc IIR;

extern particle swarm[ParticleAmount];
extern array<double,Dimension> gbest;
extern double fgbest;


void InitSwarm(network,int);

void setPbest();

void setLbest();

void setGbest();

void UpdateSwarm(int);


#endif // PSO_H
