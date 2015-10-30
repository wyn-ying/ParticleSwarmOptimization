#ifndef FINALRESULT_H
#define FINALRESULT_H

#include "parameters.h"
#include <array>
#include <vector>

using std::array; using std::vector;

class finalResult
{
    public:
        finalResult();
        virtual ~finalResult();

        array<double,AlgoRepeatNum*NetwRepeatNum> solutions;
        double finalSolution;

        array<int,AlgoRepeatNum*NetwRepeatNum> speeds;
        double finalSpeed;

        vector<int> successRuns;
        double succRate;

        void countSuccessRuns();
        double calcuFinalSolution();
        double calcuFinalSpeed();
        double calcuFinalSuccRate();

    protected:
    private:
};

#endif // FINALRESULT_H
