#pragma once

#include "network.h"
#include "binTreeNetwork.h"

network hierarchyNetworkConstruct(double p_hierarchy);

network hierarchyNetworkConstruct(double,int);

double GRCCalculate(networkMatrix,network);//calculate the global reaching centrality
