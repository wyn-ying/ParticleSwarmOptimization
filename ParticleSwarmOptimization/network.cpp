#include "network.h"

networkMatrix generateAdjacMatrix(network _network)
{
	networkMatrix temp;
	for(int i=0;i!=nodeNum;++i)
		for(int j=0;j!=nodeNum;++j)
			temp[i][j]=0;
	for(int i=0;i!=nodeNum;++i)
		for(auto it=_network[i].neighborsID.begin();it!=_network[i].neighborsID.end();++it)
			temp[i][*it]=1;
	return temp;
}



