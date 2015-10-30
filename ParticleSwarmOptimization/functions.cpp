#include "functions.h"

double round(double x)
{
	return (x>0.0)?floor(x+0.5):ceil(x-0.5);
}

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

benchmarkFunc qua(-1.28,1.28,0.05);

double QuaCalc(array<double,Dimension> x)
{
	double f=0;
	int i;
	for (i=0;i<=Dimension-1;++i)
	{
		f=f+(i+1)*pow(x[i],4);
	}
	f=f+getRandWithin_0_1();
	return f;
}

benchmarkFunc griwank(-600,600,0.05);

double GriwenkCalc(array<double,Dimension> x)
{
	double f=0,f1=0,f2=1;
	int i;
	for(i=0;i<Dimension;i++)
	{
		f1=x[i]*x[i]+f1;
		f2=cos(x[i]/sqrt((double)i+1))*f2;
	}
	f=(f1/4000)-f2+1;
	return f;
}

benchmarkFunc ackley(-32,32,0.05);

double AckleyCalc(array<double,Dimension> x)
{
	double f=0,f1=0,f2=0;
	int i;
	for (i=0;i<=Dimension-1;i++)
	{
		f1=f1+pow(x[i],2);
		f2=f2+cos(2*PI*x[i]);
	}
	f1=f1/Dimension;
	f2=f2/Dimension;
	f1=-0.2*sqrt(f1);
	f=-20*exp(f1)-exp(f2)+20+exp((double)1);
	return f;
}

benchmarkFunc weierstrass(-0.5,0.5,0.01);

double WeierstrassCalc(array<double,Dimension> x)
{
	double fx=0;
	int d,k;
	const int kmax=20;
	double ea[kmax+1];
	double eb[kmax+1];
	for(int k=0;k<kmax+1;k++){
		ea[k]=pow((double)0.5,k);
		eb[k]=pow(3.0,k);
	}
	for(k=kmax;k>=0;k--){
		for(d=0;d<Dimension;d++)
			fx+=ea[k]*(cos(eb[k]*(x[d]+0.5)*M_2PI)-cos(PI*eb[k]));
	}
	return fx;
}

benchmarkFunc noncontinuousRas(-5.12,5.12,100);

double NoncontinuousRasCalc(array<double,Dimension> x)
{
	double fx=0;;
	double y;
	int d;
	for(d=0;d<Dimension;d++){
		if(abs(x[d])<0.5){
			y=x[d];
		}else{
			y=round(2.0*x[d])/2;
		}
		fx+=y*y-10*cos(M_2PI*y)+10;
	}
	return fx;
}

benchmarkFunc schwefel_P2_22(-10,10,0.01);

double Schwefel_P2_22Calc(array<double,Dimension> x)
{
	double fx=0,fx1=0,fx2=1;
	int d;
	for(d=0;d<Dimension;d++){
		fx1=fx1+abs(x[d]);
		fx2=fx2*abs(x[d]);
	}
	fx=fx1+fx2;
	return fx;
}

benchmarkFunc noise_1(-1.28,1.28,0.05);

double Noise_1Calc(array<double,Dimension> x)
{
	double fx=0;
	int d;
	for(d=0;d<Dimension;d++){
		fx=fx+pow(x[d],4)*(d+1);
	}
	fx=fx+getRandWithin_0_1();
	return fx;
}

