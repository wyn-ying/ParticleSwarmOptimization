#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <array>
#include <cstddef>

#include "network.h"
#include "PSO.h"
#include "parameters.h"
#include "finalResult.h"

using namespace std;

int main()
{
    networkMatrix MatrixOfHierarchyNetwork;
    ofstream outputResults("results.txt");
    for(int i=0;i<=20;i++)
    {
        finalResult SphereResult;
        finalResult RosenbrockResult;
        finalResult RastriginResult;
        double p=(double)i/20;

        for(int funcID=1;funcID<=3;++funcID)
        {
            cout<<"p="<<p<<"\t"<<"FuncID="<<funcID<<endl;
            for(int nrepeat=0;nrepeat!=NetwRepeatNum;++nrepeat)
            {
                NetworkConstruct(p);
                MatrixOfHierarchyNetwork=generateAdjacMatrix();
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
                    thisRun=RunPSO(MatrixOfHierarchyNetwork,funcID);
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

        outputResults<<p<<"\t"<<SphereResult.finalSolution<<"\t"<<SphereResult.finalSpeed<<"\t"<<SphereResult.succRate
                     <<"\t"<<RosenbrockResult.finalSolution<<"\t"<<RosenbrockResult.finalSpeed<<"\t"<<RosenbrockResult.succRate
                     <<"\t"<<RastriginResult.finalSolution<<"\t"<<RastriginResult.finalSpeed<<"\t"<<RastriginResult.succRate<<endl;

    }
    outputResults.close();
    return 0;
}
