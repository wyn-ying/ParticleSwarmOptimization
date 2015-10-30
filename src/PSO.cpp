#include "PSO.h"

extern benchmarkFunc sphere;
extern benchmarkFunc rosenbrock;
extern benchmarkFunc rastrigin;

/**< the swarm of PSO */
particle swarm[ParticleAmount];

/**< the global best */
array<double,Dimension> gbest={};
double fgbest=0;

/**< structure of the swarm */
array<array<int,ParticleAmount>,ParticleAmount> structure;


void setPbest()
{
    for(int i=0;i!=ParticleAmount;++i)
    {
        if(swarm[i].fitness < swarm[i].fpbest)
        {
            swarm[i].pbest=swarm[i].position;
            swarm[i].fpbest=swarm[i].fitness;
        }
    }
}

void setLbest()
{
    for(int i=0;i!=ParticleAmount;++i)
    {
        int lbestID=swarm[i].neighborsID[0];
        for(auto it=swarm[i].neighborsID.begin();it!=swarm[i].neighborsID.end();++it)
        {
            if(swarm[*it].fpbest < swarm[lbestID].fpbest)
            {
                lbestID=*it;
            }
        }
        swarm[i].lbest=swarm[lbestID].pbest;
        swarm[i].flbest=swarm[lbestID].fpbest;
    }
}

void setGbest()
{
    int gbestID=0;
    for(int i=0;i!=ParticleAmount;++i)
    {
        if(swarm[i].fpbest <swarm[gbestID].fpbest)
            gbestID=i;
    }
    fgbest=swarm[gbestID].fpbest;
    gbest=swarm[gbestID].pbest;
}

/**< initiate the swarm with a specific structure and assign random positions and velocities */
void InitSwarm(networkMatrix adjacMatrix,int funcID)
{
    structure={};
    structure=adjacMatrix;
    for(int i=0;i!=ParticleAmount;++i)
    {
        swarm[i].reset();
        swarm[i].particleID=i;
        for(int j=0;j!=ParticleAmount;++j)
        {
            if(structure[i][j]==1 || j==i)
                swarm[i].neighborsID.push_back(j);
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
        }
        /**< set the initial value as the pbest and lbest */
        swarm[i].pbest=swarm[i].position;
        swarm[i].fpbest=swarm[i].fitness;
    }
    setLbest();
    setGbest();
//    cout<<"In initiation, fgbest="<<fgbest<<endl;
//    system("pause");
}

void UpdateSwarm(int funcID)
{
    for(int i=0;i!=ParticleAmount;++i)
    {
        for(int j=0;j!=Dimension;++j)
        {
            swarm[i].velocity[j]=Chi*(swarm[i].velocity[j]+B*getRandWithin_0_1()*(swarm[i].pbest[j]-swarm[i].position[j])
                                      +B*getRandWithin_0_1()*(swarm[i].lbest[j]-swarm[i].position[j]));
            swarm[i].position[j]=swarm[i].position[j]+swarm[i].velocity[j];
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
        }
    }
}


performance RunPSO(networkMatrix adjacMatrix,int funcID)
{
    srand((unsigned)time(0));
    rand();
    InitSwarm(adjacMatrix,funcID);

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
        }
//        cout<<fgbest<<endl;
        ++iter;
    }
    resultOfThisRun.solution=fgbest;
    return resultOfThisRun;
}
