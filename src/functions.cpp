#include "functions.h"

benchmarkFunc sphere(-100,100,0.01);

double SphereCalc(array<double,Dimension> x)
{
    double f=0;
	int i;
	for(i=0;i!=Dimension;++i)
		f=f+x[i]*x[i];
	return f;
}


benchmarkFunc rosenbrock(-30,30,100);

double RosenbrockCalc(array<double,Dimension> x)
{
    double f=0;
	int i;
	for(i=0;i!=Dimension;++i)
		f=f+(100*(x[i+1]-x[i]*x[i])*(x[i+1]-x[i]*x[i])+(x[i]-1)*(x[i]-1));
	return f;
}

benchmarkFunc rastrigin(-5.12,5.12,100);

double RastriginCalc(array<double,Dimension> x)
{
    double f=0;
	int i;
	for(i=0;i!=Dimension;++i)
		f=x[i]*x[i]-10*cos(2*PI*x[i])+10+f;
	return f;
}
