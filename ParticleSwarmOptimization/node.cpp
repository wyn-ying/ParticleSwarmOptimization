#include "node.h"


node::node(void)
{
	nodeID=0;
	lvl=0;
	neighborsID.clear();
	upperNeighborsID.clear();
	lowerNeighborsID.clear();
	localReachingCentrality=0;
	degree=0;
	p_linked=0;
	toBeChosenID.clear();
}


node::~node(void)
{
}

void node::reset()
{
	nodeID=0;
	lvl=0;
	neighborsID.clear();
	upperNeighborsID.clear();
	lowerNeighborsID.clear();
	localReachingCentrality=0;
	degree=0;
	p_linked=0;
	toBeChosenID.clear();
}
