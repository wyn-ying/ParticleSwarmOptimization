#include "finalResult.h"
#include "FIPS.h"
#include "PSO.h"
#include <fstream>
#include "Networks.h"
#include <algorithm>
#include "ringNetwork.h"
#include "HSWNetwork.h"

void InitSwarmOfMSPSO(network,int);

int MSPSOsetGbest();

performance MSPSO(network,int);

void runMSPSO();

void runMSPSO_analyze();