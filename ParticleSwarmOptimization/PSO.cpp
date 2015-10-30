#include "PSO.h"

//extern benchmarkFunc sphere;
//extern benchmarkFunc rosenbrock;
//extern benchmarkFunc rastrigin;
//extern benchmarkFunc qua;
//extern benchmarkFunc griwank;
//extern benchmarkFunc ackley;
//extern benchmarkFunc weierstrass;
//extern benchmarkFunc noncontinuousRas;
//extern benchmarkFunc schwefel_P2_22;
//extern benchmarkFunc noise_1;

/**< the swarm of PSO */
particle swarm[ParticleAmount];

/**< the global best */
array<double,Dimension> gbest={};
double fgbest=0;


void setPbest()
{
	for(int i=0;i!=ParticleAmount;++i)
	{
		if(swarm[i].fitness < swarm[i].fpbest)
		{
			swarm[i].pbest=swarm[i].position;
			swarm[i].fpbest=swarm[i].fitness;
		}
	}
}

void setLbest()
{
	for(int i=0;i!=ParticleAmount;++i)
	{
		int lbestID=swarm[i].neighborsID[0];
		for(auto it=swarm[i].neighborsID.begin();it!=swarm[i].neighborsID.end();++it)
		{
			if(swarm[*it].fpbest < swarm[lbestID].fpbest)
			{
				lbestID=*it;
			}
		}
		swarm[i].lbest=swarm[lbestID].pbest;
		swarm[i].flbest=swarm[lbestID].fpbest;
	}
}

void setGbest()
{
	int gbestID=0;
	for(int i=0;i!=ParticleAmount;++i)
	{
		if(swarm[i].fpbest <swarm[gbestID].fpbest)
			gbestID=i;
	}
	fgbest=swarm[gbestID].fpbest;
	gbest=swarm[gbestID].pbest;

}

/**< initiate the swarm with a specific structure and assign random positions and velocities */
void InitSwarm(network _network,int funcID)
{	
	for(int i=0;i!=ParticleAmount;++i)
	{
		swarm[i].reset();
		swarm[i].particleID=i;
		swarm[i].neighborsID=_network[i].neighborsID;
		swarm[i].neighborsID.push_back(i);
	}
	for(int i=0;i!=ParticleAmount;++i)
	{
		for(int j=0;j!=Dimension;++j)
		{
			switch(funcID)
			{
			case 1:
				swarm[i].position[j]=getRandWithin_0_1()*(sphere.upper-sphere.lower)+sphere.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(sphere.upper-sphere.lower)+sphere.lower;
				break;
			case 2:
				swarm[i].position[j]=getRandWithin_0_1()*(rosenbrock.upper-rosenbrock.lower)+rosenbrock.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(rosenbrock.upper-rosenbrock.lower)+rosenbrock.lower;
				break;
			case 3:
				swarm[i].position[j]=getRandWithin_0_1()*(rastrigin.upper-rastrigin.lower)+rastrigin.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(rastrigin.upper-rastrigin.lower)+rastrigin.lower;
				break;
			case 4:
				swarm[i].position[j]=getRandWithin_0_1()*(qua.upper-qua.lower)+qua.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(qua.upper-qua.lower)+qua.lower;
				break;
			case 5:
				swarm[i].position[j]=getRandWithin_0_1()*(griwank.upper-griwank.lower)+griwank.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(griwank.upper-griwank.lower)+griwank.lower;
				break;
			case 6:
				swarm[i].position[j]=getRandWithin_0_1()*(ackley.upper-ackley.lower)+ackley.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(ackley.upper-ackley.lower)+ackley.lower;
				break;
			case 7:
				swarm[i].position[j]=getRandWithin_0_1()*(weierstrass.upper-weierstrass.lower)+weierstrass.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(weierstrass.upper-weierstrass.lower)+weierstrass.lower;
				break;
			case 8:
				swarm[i].position[j]=getRandWithin_0_1()*(noncontinuousRas.upper-noncontinuousRas.lower)+noncontinuousRas.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(noncontinuousRas.upper-noncontinuousRas.lower)+noncontinuousRas.lower;
				break;
			case 9:
				swarm[i].position[j]=getRandWithin_0_1()*(schwefel_P2_22.upper-schwefel_P2_22.lower)+schwefel_P2_22.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(schwefel_P2_22.upper-schwefel_P2_22.lower)+schwefel_P2_22.lower;
				break;
			case 10:
				swarm[i].position[j]=getRandWithin_0_1()*(noise_1.upper-noise_1.lower)+noise_1.lower;
				swarm[i].velocity[j]=getRandWithin_0_1()*(noise_1.upper-noise_1.lower)+noise_1.lower;
				break;
			}
		}
	}
	for(int i=0;i!=ParticleAmount;++i)
	{
		switch(funcID)
		{
		case 1:
			swarm[i].fitness=SphereCalc(swarm[i].position);break;
		case 2:
			swarm[i].fitness=RosenbrockCalc(swarm[i].position);break;
		case 3:
			swarm[i].fitness=RastriginCalc(swarm[i].position);break;
		case 4:
			swarm[i].fitness=QuaCalc(swarm[i].position);break;
		case 5:
			swarm[i].fitness=GriwenkCalc(swarm[i].position);break;
		case 6:
			swarm[i].fitness=AckleyCalc(swarm[i].position);break;
		case 7:
			swarm[i].fitness=WeierstrassCalc(swarm[i].position);break;
		case 8:
			swarm[i].fitness=NoncontinuousRasCalc(swarm[i].position);break;
		case 9:
			swarm[i].fitness=Schwefel_P2_22Calc(swarm[i].position);break;
		case 10:
			swarm[i].fitness=Noise_1Calc(swarm[i].position);break;

		}
		/**< set the initial value as the pbest and lbest */
		swarm[i].pbest=swarm[i].position;
		swarm[i].fpbest=swarm[i].fitness;
	}
	setLbest();
	setGbest();
	//    cout<<"In initiation, fgbest="<<fgbest<<endl;
	//    system("pause");
}

void UpdateSwarm(int funcID)
{
	for(int i=0;i!=ParticleAmount;++i)
	{
		for(int j=0;j!=Dimension;++j)
		{
			swarm[i].velocity[j]=Chi*(swarm[i].velocity[j]+B*getRandWithin_0_1()*(swarm[i].pbest[j]-swarm[i].position[j])
				+B*getRandWithin_0_1()*(swarm[i].lbest[j]-swarm[i].position[j]));
			swarm[i].position[j]=swarm[i].position[j]+swarm[i].velocity[j];
		}
	}
	for(int i=0;i!=ParticleAmount;++i)
	{
		switch(funcID)
		{
		case 1:
			swarm[i].fitness=SphereCalc(swarm[i].position);break;
		case 2:
			swarm[i].fitness=RosenbrockCalc(swarm[i].position);break;
		case 3:
			swarm[i].fitness=RastriginCalc(swarm[i].position);break;
		case 4:
			swarm[i].fitness=QuaCalc(swarm[i].position);break;
		case 5:
			swarm[i].fitness=GriwenkCalc(swarm[i].position);break;
		case 6:
			swarm[i].fitness=AckleyCalc(swarm[i].position);break;
		case 7:
			swarm[i].fitness=WeierstrassCalc(swarm[i].position);break;
		case 8:
			swarm[i].fitness=NoncontinuousRasCalc(swarm[i].position);break;
		case 9:
			swarm[i].fitness=Schwefel_P2_22Calc(swarm[i].position);break;
		case 10:
			swarm[i].fitness=Noise_1Calc(swarm[i].position);break;
		}
	}
}


