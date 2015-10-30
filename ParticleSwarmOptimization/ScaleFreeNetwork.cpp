#include "ScaleFreeNetwork.h"

using std::cout;using std::endl;

network ScaleFreeNetworkConstruct(int m_0,int m)//m_0 is the amount of origin nodes, and connect the new node to m existing nodes
{
	network SFnetwork;
	//init
	for(int i=0;i!=m_0;++i)
	{
		for (int j=0;j!=m_0;++j)
		{
			if (j==i)
				continue;
			else
			{
				SFnetwork[i].neighborsID.push_back(j);
			}
		}
	}
	//add links
	for (int i=m_0;i!=nodeNum;++i)
	{		
		for (int k=0;k!=i;++k)
		{
			SFnetwork[i].toBeChosenID.push_back(k);
		}
		for (int j=0;j!=m;++j)//for node i, add m links to existing nodes
		{
			int degreeSum=0;
			for (auto it=SFnetwork[i].toBeChosenID.begin();it!=SFnetwork[i].toBeChosenID.end();++it)
			{
				SFnetwork[*it].degree=SFnetwork[*it].neighborsID.size();
				degreeSum+=SFnetwork[*it].degree;
			}
			for (auto it=SFnetwork[i].toBeChosenID.begin();it!=SFnetwork[i].toBeChosenID.end();++it)
			{
				SFnetwork[*it].p_linked=(double)SFnetwork[*it].degree/degreeSum;
			}
			double p_rand=getRandWithin_0_1();
			double p_add=0;
			vector<int>::iterator itChosen;
			for (itChosen=SFnetwork[i].toBeChosenID.begin();itChosen!=SFnetwork[i].toBeChosenID.end();++itChosen)
			{
				p_add+=SFnetwork[*itChosen].p_linked;
				if(p_add>p_rand)
					break;
			}
			SFnetwork[*itChosen].neighborsID.push_back(i);
			SFnetwork[i].neighborsID.push_back(*itChosen);
			SFnetwork[i].toBeChosenID.erase(itChosen);
		}
	}
	for (int i=0;i!=nodeNum;++i)
	{
		SFnetwork[i].degree=SFnetwork[i].neighborsID.size();
	}
	for (int i=0;i!=nodeNum;++i)
	{
		for (auto it=SFnetwork[i].neighborsID.begin();it!=SFnetwork[i].neighborsID.end();++it)
		{
			if (SFnetwork[*it].degree>SFnetwork[i].degree)
			{
				SFnetwork[i].upperNeighborsID.push_back(*it);
			}
			else
			{
				SFnetwork[i].lowerNeighborsID.push_back(*it);
			}
		}
	}
	return SFnetwork;
}