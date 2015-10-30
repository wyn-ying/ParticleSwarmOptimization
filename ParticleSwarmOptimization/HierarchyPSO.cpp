#include "HierarchyPSO.h"


void initWithDirection(network _network,int funcID)
{
	particle temp[ParticleAmount];
	for(int i=0;i!=ParticleAmount;++i)
	{
		temp[i].reset();
		temp[i].particleID=i;
		temp[i].neighborsID=_network[i].neighborsID;
		swarm[i].reset();
	}
	for (int i=0;i!=ParticleAmount;++i)
	{
		for (auto it=temp[i].neighborsID.begin();it!=temp[i].neighborsID.end();++it)
		{
			swarm[*it].neighborsID.push_back(i);
		}
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
		}
		/**< set the initial value as the pbest and lbest */
		swarm[i].pbest=swarm[i].position;
		swarm[i].fpbest=swarm[i].fitness;
	}
	setLbest();
	setGbest();
}

performance HierarchyPSO(network _network,int funcID)
{
	initWithDirection(_network,funcID);

	int iter=0;
	int hasConverged=0;
	performance resultOfThisRun;
	while(iter < MaxIteration)
	{
		UpdateSwarm(funcID);
		setPbest();
		setLbest();
		setGbest();
		switch(funcID)
		{
		case 1:
			if(fgbest<sphere.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 2:
			if(fgbest<rosenbrock.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 3:
			if(fgbest<rastrigin.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 4:
			if(fgbest<qua.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 5:
			if(fgbest<griwank.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		}
		//        cout<<fgbest<<endl;
		++iter;
	}
	resultOfThisRun.solution=fgbest;
	return resultOfThisRun;
}

void RunHierarchyPSO()
{
	network hierarchyNetwork;
	ofstream outputResults("resultsOfHierarchyPSO.txt");
	srand((unsigned)time(0));
	rand();
	for(int i=0;i<=20;i++)
	{
		finalResult SphereResult;
		finalResult RosenbrockResult;
		finalResult RastriginResult;
		finalResult QuaResult;
		finalResult GriwankResult;
		double p=(double)i/20;

		/**< funcID:                 funcName:          */
		/**<    1                      sphere           */
		/**<    2                      rosenbrock       */
		/**<    3                      rastrigin        */
		/**<    4                      qua              */
		/**<    5                      griwank          */
		for(int funcID=1;funcID<=5;++funcID)
		{
			cout<<"p="<<p<<"\t"<<"FuncID="<<funcID<<endl;
			for(int nrepeat=0;nrepeat!=NetwRepeatNum;++nrepeat)
			{
				hierarchyNetwork=hierarchyNetworkConstruct(p);
				//                cout<<"adjacMatrix generated successfully!"<<endl;
				//                for(int i=0;i!=nodeNum;++i)
				//                {
				//                    for(int j=0;j!=nodeNum;++j)
				//                        cout<<MatrixOfHierarchyNetwork[i][j]<<"\t";
				//                    cout<<endl;
				//                }
				//                system("pause");
				for(int arepeat=0;arepeat!=AlgoRepeatNum;++arepeat)
				{
					performance thisRun;
					thisRun=HierarchyPSO(hierarchyNetwork,funcID);
					switch(funcID)
					{
					case 1:
						SphereResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
						SphereResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
						break;
					case 2:
						RosenbrockResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
						RosenbrockResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
						break;
					case 3:
						RastriginResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
						RastriginResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
						break;
					case 4:
						QuaResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
						QuaResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
						break;
					case 5:
						GriwankResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
						GriwankResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
						break;
					}
				}
			}
		}
		SphereResult.finalSolution=SphereResult.calcuFinalSolution();
		SphereResult.finalSpeed=SphereResult.calcuFinalSpeed();
		SphereResult.succRate=SphereResult.calcuFinalSuccRate();

		RosenbrockResult.finalSolution=RosenbrockResult.calcuFinalSolution();
		RosenbrockResult.finalSpeed=RosenbrockResult.calcuFinalSpeed();
		RosenbrockResult.succRate=RosenbrockResult.calcuFinalSuccRate();

		RastriginResult.finalSolution=RastriginResult.calcuFinalSolution();
		RastriginResult.finalSpeed=RastriginResult.calcuFinalSpeed();
		RastriginResult.succRate=RastriginResult.calcuFinalSuccRate();

		QuaResult.finalSolution=QuaResult.calcuFinalSolution();
		QuaResult.finalSpeed=QuaResult.calcuFinalSpeed();
		QuaResult.succRate=QuaResult.calcuFinalSuccRate();

		GriwankResult.finalSolution=GriwankResult.calcuFinalSolution();
		GriwankResult.finalSpeed=GriwankResult.calcuFinalSpeed();
		GriwankResult.succRate=GriwankResult.calcuFinalSuccRate();

		outputResults<<p<<"\t"<<SphereResult.finalSolution<<"\t"<<SphereResult.finalSpeed<<"\t"<<SphereResult.succRate
			<<"\t"<<RosenbrockResult.finalSolution<<"\t"<<RosenbrockResult.finalSpeed<<"\t"<<RosenbrockResult.succRate
			<<"\t"<<RastriginResult.finalSolution<<"\t"<<RastriginResult.finalSpeed<<"\t"<<RastriginResult.succRate
			<<"\t"<<QuaResult.finalSolution<<"\t"<<QuaResult.finalSpeed<<"\t"<<QuaResult.succRate
			<<"\t"<<GriwankResult.finalSolution<<"\t"<<GriwankResult.finalSpeed<<"\t"<<GriwankResult.succRate
			<<endl;

	}
	outputResults.close();
}