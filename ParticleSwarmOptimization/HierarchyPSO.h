#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <array>
#include <cstddef>

#include "hierarchyNetwork.h"
#include "standardPSO.h"
#include "parameters.h"
#include "finalResult.h"
#include "PSO.h"


void initWithDirection(network,int);

performance HierarchyPSO(network,int);

void RunHierarchyPSO();