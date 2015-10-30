#include "fullyConnectedNetwork.h"


network fullyConnectedNetwConstruct()
{
	network fullyConnectedNetw;
	for (int i=0;i!=nodeNum;++i)
	{
		for (int j=0;j!=nodeNum;++j)
		{
			if(j==i)
				continue;
			else
				fullyConnectedNetw[i].neighborsID.push_back(j);
		}
	}
	return fullyConnectedNetw;
}