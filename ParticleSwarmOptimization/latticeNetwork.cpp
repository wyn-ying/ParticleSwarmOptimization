#include "latticeNetwork.h"
//为了结构整齐只有49个粒子，注意改粒子数

network latticeConstruct()
{
	network	lattice;
	for (int i = 1; i <= 5; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i + 42);
	}
	for (int i = 8; i <= 12; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i - 7);
	}
	for (int i = 15; i <= 19; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i - 7);
	}
	for (int i = 22; i <= 26; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i - 7);
	}
	for (int i = 29; i <= 33; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i - 7);
	}
	for (int i = 36; i <= 40; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i + 7);
		lattice[i].neighborsID.push_back(i - 7);
	}
	for (int i = 43; i <= 47; i++)
	{
		lattice[i].neighborsID.push_back(i - 1);
		lattice[i].neighborsID.push_back(i + 1);
		lattice[i].neighborsID.push_back(i - 7);
		lattice[i].neighborsID.push_back(i - 42);
	}
	return lattice;
}
