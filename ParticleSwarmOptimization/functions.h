/**< funcID:                 funcName:          */
/**<    1                      sphere           */
/**<    2                      rosenbrock       */
/**<    3                      rastrigin        */
/**<    4                      qua              */
/**<    5                      griwank          */
/**<    6                      ackley           */
/**<    7                      weierstrass      */
/**<    8                      noncontinusRas   */
/**<    9                      schwefel_P2.22   */
/**<    10                      noise_1         */


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "parameters.h"
#include "benchmarkFunc.h"
#include <array>
#include <cmath>
#include "randomNumGenerator.h"

using std::array;

double round(double);

double SphereCalc(array<double,Dimension>);

double RosenbrockCalc(array<double,Dimension>);

double RastriginCalc(array<double,Dimension>);

double QuaCalc(array<double,Dimension>);

double GriwenkCalc(array<double,Dimension>);

double AckleyCalc(array<double,Dimension>);

double WeierstrassCalc(array<double,Dimension>);

double NoncontinuousRasCalc(array<double,Dimension>);

double Schwefel_P2_22Calc(array<double,Dimension>);

double Noise_1Calc(array<double,Dimension>);

double IIRCalc(array<double, Dimension>);

#endif // FUNCTIONS_H
