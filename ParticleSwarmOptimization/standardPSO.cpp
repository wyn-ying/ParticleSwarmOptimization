#include "standardPSO.h"

performance standardPSO(network _network,int funcID)
{
	InitSwarm(_network,funcID);
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
		case 6:
			if(fgbest<ackley.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 7:
			if(fgbest<weierstrass.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 8:
			if(fgbest<noncontinuousRas.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 9:
			if(fgbest<schwefel_P2_22.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;
		case 10:
			if(fgbest<noise_1.goal && hasConverged==0)
			{
				hasConverged=1;
				resultOfThisRun.speed=iter;
			}
			break;

		}
		//cout<<iter<<"\t"<<fgbest<<endl;
		++iter;
	}
	resultOfThisRun.solution=fgbest;
	return resultOfThisRun;
}

void runSDPSO()
{
	network inputNetwork;
	ofstream outputResults("resultsOfSDPSO.txt");
	finalResult SphereResult;
	finalResult RosenbrockResult;
	finalResult RastriginResult;
	finalResult QuaResult;
	finalResult GriwankResult;
	finalResult AckleyResult;
	finalResult weierstrassResult;
	finalResult noncontinuousRasResult;
	finalResult schwefel_P2_22Result;
	finalResult noise_1Result;

	srand((unsigned)time(0));
	rand();
	for(int funcID=6;funcID<=10;++funcID)
	{
		cout<<"FuncID="<<funcID<<endl;
		for(int nrepeat=0;nrepeat!=NetwRepeatNum;++nrepeat)
		{
			for (int i=0;i!=nodeNum;++i)
			{
				inputNetwork[i].reset();
			}
			inputNetwork=fullyConnectedNetwConstruct();
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
				thisRun=standardPSO(inputNetwork,funcID);
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
				case 6:
					AckleyResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
					AckleyResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
					break;
				case 7:
					weierstrassResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
					weierstrassResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
					break;
				case 8:
					noncontinuousRasResult.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
					noncontinuousRasResult.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
					break;
				case 9:
					schwefel_P2_22Result.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
					schwefel_P2_22Result.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
					break;
				case 10:
					noise_1Result.solutions[nrepeat*AlgoRepeatNum+arepeat]=thisRun.solution;
					noise_1Result.speeds[nrepeat*AlgoRepeatNum+arepeat]=thisRun.speed;
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

		AckleyResult.finalSolution=AckleyResult.calcuFinalSolution();
		AckleyResult.finalSpeed=AckleyResult.calcuFinalSpeed();
		AckleyResult.succRate=AckleyResult.calcuFinalSuccRate();

		weierstrassResult.finalSolution=weierstrassResult.calcuFinalSolution();
		weierstrassResult.finalSpeed=weierstrassResult.calcuFinalSpeed();
		weierstrassResult.succRate=weierstrassResult.calcuFinalSuccRate();

		noncontinuousRasResult.finalSolution=noncontinuousRasResult.calcuFinalSolution();
		noncontinuousRasResult.finalSpeed=noncontinuousRasResult.calcuFinalSpeed();
		noncontinuousRasResult.succRate=noncontinuousRasResult.calcuFinalSuccRate();

		schwefel_P2_22Result.finalSolution=schwefel_P2_22Result.calcuFinalSolution();
		schwefel_P2_22Result.finalSpeed=schwefel_P2_22Result.calcuFinalSpeed();
		schwefel_P2_22Result.succRate=schwefel_P2_22Result.calcuFinalSuccRate();

		noise_1Result.finalSolution=noise_1Result.calcuFinalSolution();
		noise_1Result.finalSpeed=noise_1Result.calcuFinalSpeed();
		noise_1Result.succRate=noise_1Result.calcuFinalSuccRate();


		outputResults<<SphereResult.finalSolution<<"\t"<<SphereResult.finalSpeed<<"\t"<<SphereResult.succRate
			<<"\t"<<RosenbrockResult.finalSolution<<"\t"<<RosenbrockResult.finalSpeed<<"\t"<<RosenbrockResult.succRate
			<<"\t"<<RastriginResult.finalSolution<<"\t"<<RastriginResult.finalSpeed<<"\t"<<RastriginResult.succRate
			<<"\t"<<QuaResult.finalSolution<<"\t"<<QuaResult.finalSpeed<<"\t"<<QuaResult.succRate
			<<"\t"<<GriwankResult.finalSolution<<"\t"<<GriwankResult.finalSpeed<<"\t"<<GriwankResult.succRate
			<<"\t"<<AckleyResult.finalSolution<<"\t"<<AckleyResult.finalSpeed<<"\t"<<AckleyResult.succRate
			<<"\t"<<weierstrassResult.finalSolution<<"\t"<<weierstrassResult.finalSpeed<<"\t"<<weierstrassResult.succRate
			<<"\t"<<noncontinuousRasResult.finalSolution<<"\t"<<noncontinuousRasResult.finalSpeed<<"\t"<<noncontinuousRasResult.succRate
			<<"\t"<<schwefel_P2_22Result.finalSolution<<"\t"<<schwefel_P2_22Result.finalSpeed<<"\t"<<schwefel_P2_22Result.succRate
			<<"\t"<<noise_1Result.finalSolution<<"\t"<<noise_1Result.finalSpeed<<"\t"<<noise_1Result.succRate
			<<endl;

	outputResults.close();
}