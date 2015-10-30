#pragma once

#include <vector>

using std::vector;

class node
{
public:
	int nodeID;//ID of the node
	int lvl;//the hierarchy level the node is in, the higher the lvl value, the upper hierarchy it in
	vector<int> neighborsID;//ID of this node's neighbors
	int degree;

	//for scale-free network
	double p_linked;//the probability to be linked
	vector<int> toBeChosenID;

	//these two are for hierarchy networks
	vector<int> upperNeighborsID;
	vector<int> lowerNeighborsID;
	double localReachingCentrality;
public:
	node(void);
	~node(void);
	void reset();
};

