#ifndef NETWORK_H
#define NETWORK_H

#include "randomNumGenerator.h"
#include "parameters.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>


using namespace std;

const int nodeNum=ParticleAmount;//the scale of the network

typedef array<array<int,nodeNum>,nodeNum> networkMatrix;

typedef struct{
    int nodeID;//ID of the node
    unsigned lvl;//the hierarchy level the node is in
    vector<int> neighborsID;//ID of this node's neighbors
    double localReachingCentrality;
} node;//each node of the network

void NetworkConstruct(double p_hierarchy);

networkMatrix generateAdjacMatrix();

double GRCCalculate(networkMatrix adjacMatrix);//calculate the global reaching centrality

#endif // NETWORK_H
