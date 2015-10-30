#pragma once

#include <fstream>

#include "PSO.h"
#include "binTreeNetwork.h"
#include "finalResult.h"
#include "ScaleFreeNetwork.h"

using std::fstream;

performance PartlyFeedbackPSO(network,int,double);

void initWithPartialFeedback(network,int);

void runPFPSO();

void setLbestWithPartialFeedback(double);