#include "hierarchyNetwork.h"

network hierarchyNetworkConstruct(double p_hierarchy)
{
	int i,j;//temp cycling variable

	//construct the original directed tree	
	network hierarchyNetwork;
	for (int i=0;i!=nodeNum;++i)
	{
		hierarchyNetwork[i].reset();
	}
	hierarchyNetwork=TreeConstruct(2);
	for (int i=0;i!=nodeNum;++i)
	{
		hierarchyNetwork[i].neighborsID=hierarchyNetwork[i].lowerNeighborsID;
	}
	//add links

	int addLinkNum=140;
	for(i=0;i!=addLinkNum;++i)
	{
		if(getRandWithin_0_1()>p_hierarchy)//for probability 1-p_hierarchy, randomly choose two nodes and link them if not linked before
		{
			int originID=rand()%nodeNum;
			int targetID;
			do{
				targetID=rand()%nodeNum;
			}while(targetID == originID);
			if(find(hierarchyNetwork[originID].neighborsID.begin(),hierarchyNetwork[originID].neighborsID.end(),targetID)
				== hierarchyNetwork[originID].neighborsID.end())
				hierarchyNetwork[originID].neighborsID.push_back(targetID);
		}
		else
		{
			int originID=rand()%nodeNum;
			int targetID;
			do{
				targetID=rand()%nodeNum;
			}while(targetID == originID);
			if(find(hierarchyNetwork[originID].neighborsID.begin(),hierarchyNetwork[originID].neighborsID.end(),targetID)
				==hierarchyNetwork[originID].neighborsID.end() && hierarchyNetwork[originID].lvl>hierarchyNetwork[targetID].lvl)
				hierarchyNetwork[originID].neighborsID.push_back(targetID);
		}
	}
	//    cout<<"network construct successfully"<<endl;
	//
	//    system("pause");
	return hierarchyNetwork;
}


// the version that can modify the amount of links added
network hierarchyNetworkConstruct(double p_hierarchy,int addLinkNum)
{
	int i,j;//temp cycling variable

	//construct the original directed tree	
	network hierarchyNetwork;
	for (int i=0;i!=nodeNum;++i)
	{
		hierarchyNetwork[i].reset();
	}
	hierarchyNetwork=TreeConstruct(2);
	for (int i=0;i!=nodeNum;++i)
	{
		hierarchyNetwork[i].neighborsID=hierarchyNetwork[i].lowerNeighborsID;
	}
	//add links

	for(i=0;i!=addLinkNum;++i)
	{
		if(getRandWithin_0_1()>p_hierarchy)//for probability 1-p_hierarchy, randomly choose two nodes and link them if not linked before
		{
			int originID=rand()%nodeNum;
			int targetID;
			do{
				targetID=rand()%nodeNum;
			}while(targetID == originID);
			if(find(hierarchyNetwork[originID].neighborsID.begin(),hierarchyNetwork[originID].neighborsID.end(),targetID)
				== hierarchyNetwork[originID].neighborsID.end())
				hierarchyNetwork[originID].neighborsID.push_back(targetID);
		}
		else
		{
			int originID=rand()%nodeNum;
			int targetID;
			do{
				targetID=rand()%nodeNum;
			}while(targetID == originID);
			if(find(hierarchyNetwork[originID].neighborsID.begin(),hierarchyNetwork[originID].neighborsID.end(),targetID)
				==hierarchyNetwork[originID].neighborsID.end() && hierarchyNetwork[originID].lvl>hierarchyNetwork[targetID].lvl)
				hierarchyNetwork[originID].neighborsID.push_back(targetID);
		}
	}
	//    cout<<"network construct successfully"<<endl;
	//
	//    system("pause");
	return hierarchyNetwork;
}


double GRCCalculate(networkMatrix adjacMatrix,network _network)//calculate the global reaching centrality
{
	//for each node, calculate its local reaching centrality
	/**< using Warshall method */
	networkMatrix reachableMatrix=adjacMatrix;
	for(int i=0;i!=nodeNum;++i)
		for(int j=0;j!=nodeNum;++j)
			reachableMatrix[i][j]=(bool)reachableMatrix[i][j];

	for(int i=0;i!=nodeNum;++i)
	{
		for(int j=0;j!=nodeNum;++j)
		{
			if(reachableMatrix[j][i]==1)
			{
				for(int k=0;k!=nodeNum;++k)
					reachableMatrix[j][k]=reachableMatrix[j][k]||reachableMatrix[i][k];
			}
		}
	}
	/**< debug */
	//    ofstream outputReachMat("reachableTemp.txt");
	//    for(int i=0;i!=nodeNum;++i)
	//    {
	//        for(int j=0;j!=nodeNum;++j)
	//            outputReachMat<<reachableMatrix[i][j]<<"\t";
	//        outputReachMat<<"\n";
	//    }
	//    outputReachMat.close();
	/**< debug */
	for(int i=0;i!=nodeNum;++i)
	{
		_network[i].localReachingCentrality=0;
		for(int j=0;j!=nodeNum;++j)
			_network[i].localReachingCentrality+=reachableMatrix[i][j];
		_network[i].localReachingCentrality=_network[i].localReachingCentrality/nodeNum;
	}
	/**< debug */
	//    for(int i=0;i!=nodeNum;++i)
	//    {
	//        cout<<network[i].localReachingCentrality<<"\t";
	//    }
	/**< debug */
	/**< GRC value */
	double LRCmaxValue=_network[0].localReachingCentrality;
	for(int i=0;i!=nodeNum;++i)
		if(_network[i].localReachingCentrality>LRCmaxValue)
			LRCmaxValue=_network[i].localReachingCentrality;
	double GRCvalue=0;
	for(int i=0;i!=nodeNum;++i)
		GRCvalue+=LRCmaxValue-_network[i].localReachingCentrality;
	GRCvalue=GRCvalue/nodeNum;
	return GRCvalue;
}