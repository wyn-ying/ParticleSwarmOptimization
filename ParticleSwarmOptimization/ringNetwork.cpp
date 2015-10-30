#include "ringNetwork.h"


network ringConstruct()//construct a standard ring network with degree=2 
{
	network ring;
	for (int i=0;i!=nodeNum;++i)
	{
		if (i>=1 && i <=nodeNum-2)
		{
			ring[i].neighborsID.push_back(i-1);
			ring[i].neighborsID.push_back(i+1);
		} 
		else if (i==0)
		{
			ring[i].neighborsID.push_back(i+1);
			ring[i].neighborsID.push_back(nodeNum-1);
		}
		else
		{
			ring[i].neighborsID.push_back(i-1);
			ring[i].neighborsID.push_back(0);
		}		
	}
	return ring;
}

network ringConstruct(int k)//construct a ring network with degree=2k
{
	network ring;
	if (k<nodeNum/2)
	{
		for (int i=0;i!=nodeNum;++i)
		{
			for (int j=i-k;j<=i+k;++j)
			{
				if (j==i)
					continue;
				else if(j<0)
					ring[i].neighborsID.push_back(j+nodeNum);
				else if(j>nodeNum-1)
					ring[i].neighborsID.push_back(j-nodeNum);
				else
					ring[i].neighborsID.push_back(j);			
			}
		}
	} 
	else
	{
		for (int i=0;i!=nodeNum;++i)
		{
			for (int j=i-k+1;j<=i+k-1;++j)
			{
				if (j==i)
					continue;
				else if(j<0)
					ring[i].neighborsID.push_back(j+nodeNum);
				else if(j>nodeNum-1)
					ring[i].neighborsID.push_back(j-nodeNum);
				else
					ring[i].neighborsID.push_back(j);			
			}
			ring[i].neighborsID.push_back(i-k<0?i+k:i-k);
		}
	}
	return ring;
}