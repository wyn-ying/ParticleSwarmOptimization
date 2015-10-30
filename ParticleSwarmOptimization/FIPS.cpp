#include "FIPS.h"

void setLbest_FIPS()
{
	for (int i=0;i!=ParticleAmount;++i)
	{
		swarm[i].lbest_FIPS.fill(0);
		for (auto it=swarm[i].neighborsID.begin();it!=swarm[i].neighborsID.end();++it)
		{
			for (int j=0;j!=Dimension;++j)
			{
				swarm[i].lbest_FIPS[j]+=getRandWithin_0_1()*2*B*(swarm[*it].pbest[j]-swarm[i].position[j]);
			}
		}
		for (int j=0;j!=Dimension;++j)
			swarm[i].lbest_FIPS[j]=swarm[i].lbest_FIPS[j]/swarm[i].neighborsID.size();
	}
}

