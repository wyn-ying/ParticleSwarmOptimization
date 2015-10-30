#ifndef NETWORK_H
#define NETWORK_H

#include "randomNumGenerator.h"
#include "parameters.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include "node.h"


using namespace std;

const int nodeNum=ParticleAmount;//the scale of the network

typedef array<node,nodeNum> network;//the network we will construct and use

typedef array<array<int,nodeNum>,nodeNum> networkMatrix;

networkMatrix generateAdjacMatrix(network);


#endif // NETWORK_H
