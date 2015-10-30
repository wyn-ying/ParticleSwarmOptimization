#include "randomNumGenerator.h"


double getRandWithin_0_1()//generate a random number in [0,1]
{
    double randNum;
	randNum=rand()/(double)RAND_MAX;
	return randNum;
}
