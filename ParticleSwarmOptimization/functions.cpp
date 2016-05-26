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
	for(i=0;i!=Dimension-1;++i)
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

benchmarkFunc IIR(-3, 3, 20);

const long double Pi = std::_Pi;
double IIRCalcE(array<double, Dimension> x, double w1, double w2)
{
	double Ar = 1 + x[0] * cos(w2) + x[1] * cos(2 * w2)
			  + x[2] * cos(w1) + x[3] * cos(w1 + w2) + x[4] * cos(w1 + 2 * w2)
			  + x[5] * cos(2 * w1) + x[6] * cos(2 * w1 + w2) + x[7] * cos(2 * (w1 + w2));
	double Ai = x[0] * sin(w2) + x[1] * sin(2 * w2)
			  + x[2] * sin(w1) + x[3] * sin(w1 + w2) + x[4] * sin(w1 + 2 * w2)
			  + x[5] * sin(2 * w1) + x[6] * sin(2 * w1 + w2) + x[7] * sin(2 * (w1 + w2));
	double B1r = 1 + x[8] * cos(w1) + x[10] * cos(w2) + x[12] * cos(w1 + w2);
	double B1i = x[8] * sin(w1) + x[10] * sin(w2) + x[12] * sin(w1 + w2);
	double B2r = 1 + x[9] * cos(w1) + x[11] * cos(w2) + x[13] * cos(w1 + w2);
	double B2i = x[9] * sin(w1) + x[11] * sin(w2) + x[13] * sin(w1 + w2);
	
	double M = x[14] * sqrt((Ar*Ar + Ai*Ai) / (B1i*B1i + B1r*B1r) / (B2i*B2i + B2r*B2r));
	double Md, threshold = sqrt(w1*w1 + w2*w2);
	if (threshold < 0.08*Pi) Md = 1;
	else if (threshold < 0.12*Pi) Md = 0.5;
	else Md = 0;
	return pow((abs(M) - Md),8);
}

double IIRCalc(array<double, Dimension> x)
{
	double fx = 0;
	for (int i = 0;i <= 50;i++) {
		for (int j = 0;j <= 50;j++) {
			fx += IIRCalcE(x, (double)i*Pi / 50, (double)j*Pi/50);
		}
	}
	return fx;
}
