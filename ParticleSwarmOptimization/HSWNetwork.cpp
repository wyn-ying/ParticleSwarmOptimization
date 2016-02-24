#include "HSWNetwork.h"

network HSWConstruct(int k, double p)//construct a ring network with degree=2k
{
	network ring;
	if (k<nodeNum / 2)
	{
		for (int i = 0;i != nodeNum;++i)
		{
			for (int j = i - k;j <= i + k;++j)
			{
				if (j == i)
					continue;
				else if (j<0)
					ring[i].neighborsID.push_back(j + nodeNum);
				else if (j>nodeNum - 1)
					ring[i].neighborsID.push_back(j - nodeNum);
				else
					ring[i].neighborsID.push_back(j);
			}
		}
	}
	else
	{
		for (int i = 0;i != nodeNum;++i)
		{
			for (int j = i - k + 1;j <= i + k - 1;++j)
			{
				if (j == i)
					continue;
				else if (j<0)
					ring[i].neighborsID.push_back(j + nodeNum);
				else if (j>nodeNum - 1)
					ring[i].neighborsID.push_back(j - nodeNum);
				else
					ring[i].neighborsID.push_back(j);
			}
			ring[i].neighborsID.push_back(i - k<0 ? i + k : i - k);
		}
	}
	int numofedge = nodeNum * k, countnum = 0;
	int targetID_1, targetID_2;
	int endID_1, endID_2;
	int tmp_1, tmp_2;
	bool notin;
	while(countnum < numofedge*p)
	{
		//select two nodeID
		//select two ends respectively from the selected nodeID
		targetID_1 = getRandWithin_0_1()*nodeNum;
		endID_1 = getRandWithin_0_1()*k * 2;
		do {
			notin = false;
			targetID_2 = getRandWithin_0_1()*nodeNum;
			for (int i = 0;i<ring[targetID_2].neighborsID.size(); i++) {
				if (ring[targetID_2].neighborsID[i] == ring[targetID_1].neighborsID[endID_1]) {
					notin = true;
					break;
				}
			}
		} while((targetID_2 == targetID_1) || (targetID_2 == ring[targetID_1].neighborsID[endID_1]) || notin);//TODO:endID_1 couldn't be in targetID_2's neighbor set
		
		do {
			notin = false;
			endID_2 = getRandWithin_0_1()*k * 2;
			for (int i = 0;i<ring[targetID_1].neighborsID.size(); i++) {
				if (ring[targetID_1].neighborsID[i] == ring[targetID_2].neighborsID[endID_2]) {
					notin = true;
					break;
				}
			}
		} while ((ring[targetID_2].neighborsID[endID_2]==targetID_1) || (ring[targetID_2].neighborsID[endID_2]== ring[targetID_1].neighborsID[endID_1]) || notin);//TODOTODO:endID_2 couldn't be in targetID_1's neighbor set
		//swap the two ends
		tmp_1 = ring[targetID_1].neighborsID[endID_1];
		tmp_2 = ring[targetID_2].neighborsID[endID_2];
		ring[targetID_1].neighborsID[endID_1] = tmp_2;
		ring[targetID_2].neighborsID[endID_2] = tmp_1;

		countnum++;
	}
	return ring;
}