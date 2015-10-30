#include "finalResult.h"

finalResult::finalResult()
{
        solutions={};
        finalSolution=0;
        speeds={};
        finalSpeed=0;
        succRate=0;
        successRuns.clear();       //ctor
}

finalResult::~finalResult()
{
    //dtor
}

void finalResult::countSuccessRuns()
{
    successRuns.clear();
    for(int i=0;i!=AlgoRepeatNum*NetwRepeatNum;++i)
    {
        if(speeds[i]!=MaxIteration)
            successRuns.push_back(i);
    }
}

double finalResult::calcuFinalSolution()
{
    countSuccessRuns();
    double result=0;
    for(auto it=successRuns.begin();it!=successRuns.end();++it)
        result+=solutions[*it];
    result=result/successRuns.size();
    return result;
}

double finalResult::calcuFinalSpeed()
{
    countSuccessRuns();
    double result=0;
    for(auto it=successRuns.begin();it!=successRuns.end();++it)
        result+=(double)speeds[*it];
    result=result/(double)successRuns.size();
    return result;
}

double finalResult::calcuFinalSuccRate()
{
    countSuccessRuns();
    double result=0;
    result=(double)successRuns.size()/(AlgoRepeatNum*NetwRepeatNum);
    return result;
}
