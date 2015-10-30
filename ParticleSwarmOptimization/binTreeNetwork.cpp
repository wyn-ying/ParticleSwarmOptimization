#include "binTreeNetwork.h"

#include <iostream>

using namespace std;

//construct a k-tree of 80 nodes 
network TreeConstruct(int k)
{
	network Tree;
	
	for (int i=0;i!=nodeNum;++i)
	{
		if (0==i)
			Tree[i].lvl=3;
		else if(i>=1 && i<=k)
			Tree[i].lvl=2;
		else if(i>=k+1 && i<=(k+1)*k)
			Tree[i].lvl=1;
		else
			Tree[i].lvl=0;
	}
	for (int i=0;i!=nodeNum;++i)
	{
		if (i*k+k<=nodeNum-1)
		{
			for (int j=i*k+1;j<=i*k+k;++j)
			{
				Tree[i].lowerNeighborsID.push_back(j);
			}
		}
		else
		{
			for (int j=i*k+1;j<=nodeNum-1;++j)
				Tree[i].lowerNeighborsID.push_back(j);
		}
	}
	for (int i=0;i!=nodeNum;++i)
	{
		for (auto it=Tree[i].lowerNeighborsID.begin();it!=Tree[i].lowerNeighborsID.end();++it)
		{
			Tree[*it].upperNeighborsID.push_back(i);
		}
	}
	return Tree;
}

network TreeWithAddedEdgesConstruct(int k,int addAmount)
{
	network Tree;
	for (int i=0;i!=nodeNum;++i)
	{
		if (0==i)
			Tree[i].lvl=3;
		else if(i>=1 && i<=k)
			Tree[i].lvl=2;
		else if(i>=k+1 && i<=(k+1)*k)
			Tree[i].lvl=1;
		else
			Tree[i].lvl=0;
	}
	for (int i=0;i!=nodeNum;++i)
	{
		if (i*k+k<=nodeNum-1)
		{
			for (int j=i*k+1;j<=i*k+k;++j)
			{
				Tree[i].lowerNeighborsID.push_back(j);
			}
		}
		else
		{
			for (int j=i*k+1;j<=nodeNum-1;++j)
				Tree[i].lowerNeighborsID.push_back(j);
		}
	}
	for (int i=0;i!=nodeNum;++i)
	{
		for (auto it=Tree[i].lowerNeighborsID.begin();it!=Tree[i].lowerNeighborsID.end();++it)
		{
			Tree[*it].upperNeighborsID.push_back(i);
		}
	}
	int count=0;
	while (count<addAmount)
	{
		int ID1=rand()%nodeNum;
		int ID2;
		do 
		{
			ID2=rand()%nodeNum;
		} while (ID2==ID1);
		if (ID1<ID2)
		{
			if (find(Tree[ID1].lowerNeighborsID.begin(),Tree[ID1].lowerNeighborsID.end(),ID2)
				== Tree[ID1].lowerNeighborsID.end())
			{
				count++;
				Tree[ID1].lowerNeighborsID.push_back(ID2);
				Tree[ID2].upperNeighborsID.push_back(ID1);
			} 
		}
		else
		{
			if (find(Tree[ID2].lowerNeighborsID.begin(),Tree[ID2].lowerNeighborsID.end(),ID1)
				== Tree[ID2].lowerNeighborsID.end())
			{
				count++;
				Tree[ID2].lowerNeighborsID.push_back(ID1);
				Tree[ID1].upperNeighborsID.push_back(ID2);
			} 
		}
	}
	return Tree;
}

