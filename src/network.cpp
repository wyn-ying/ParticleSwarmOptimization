#include "network.h"


array<node,nodeNum> network;//the network we will construct and use

void NetworkConstruct(double p_hierarchy)
{
    int i,j;//temp cycling variable
    //construct the original directed tree

    for(i=0;i!=nodeNum;++i)
    {
        network[i].nodeID=i;
        if(0<=i && i<4)
            network[i].lvl=4;
        else if(4<=i && i<12)
            network[i].lvl=3;
        else if(12<=i && i<28)
            network[i].lvl=2;
        else
            network[i].lvl=1;
    }
    for(i=0;i!=nodeNum;++i)//determine the neighbors of each node
    {
        network[i].neighborsID.clear();
        for(j=0;j!=nodeNum;++j)
        {
            if(network[j].lvl < network[i].lvl)
                network[i].neighborsID.push_back(network[j].nodeID);
        }
    }
    //add links
    srand((unsigned)time(0));
    rand();
    int addedEdgesNum=400;//the amount of edges to be added
    for(i=0;i!=addedEdgesNum;++i)
    {
        if(getRandWithin_0_1()>p_hierarchy)//for probability 1-p_hierarchy, randomly choose two nodes and link them if not linked before
        {
            int originID=rand()%nodeNum;
            int targetID;
            do{
                targetID=rand()%nodeNum;
            }while(targetID == originID);
            if(find(network[originID].neighborsID.begin(),network[originID].neighborsID.end(),targetID)
               == network[originID].neighborsID.end())
                network[originID].neighborsID.push_back(targetID);
        }
        else
        {
            int originID=rand()%nodeNum;
            int targetID;
            do{
                targetID=rand()%nodeNum;
            }while(targetID == originID);
            if(find(network[originID].neighborsID.begin(),network[originID].neighborsID.end(),targetID)
               ==network[originID].neighborsID.end() && network[originID].lvl>network[targetID].lvl)
                network[originID].neighborsID.push_back(targetID);
        }
    }
//    cout<<"network construct successfully"<<endl;
//
//    system("pause");
}


networkMatrix generateAdjacMatrix()
{
    networkMatrix temp;
    for(int i=0;i!=nodeNum;++i)
        for(int j=0;j!=nodeNum;++j)
            temp[i][j]=0;
    for(int i=0;i!=nodeNum;++i)
        for(auto it=network[i].neighborsID.begin();it!=network[i].neighborsID.end();++it)
            temp[i][*it]=1;
    return temp;
}


double GRCCalculate(networkMatrix adjacMatrix)//calculate the global reaching centrality
{
    //for each node, calculate its local reaching centrality
    /**< using Warshall method */
    networkMatrix reachableMatrix=adjacMatrix;
    for(int i=0;i!=nodeNum;++i)
        for(int j=0;j!=nodeNum;++j)
            reachableMatrix[i][j]=(bool)reachableMatrix[i][j];

    for(int i=0;i!=nodeNum;++i)
    {
        for(int j=0;j!=nodeNum;++j)
        {
            if(reachableMatrix[j][i]==1)
            {
                for(int k=0;k!=nodeNum;++k)
                    reachableMatrix[j][k]=reachableMatrix[j][k]||reachableMatrix[i][k];
            }
        }
    }
    /**< debug */
//    ofstream outputReachMat("reachableTemp.txt");
//    for(int i=0;i!=nodeNum;++i)
//    {
//        for(int j=0;j!=nodeNum;++j)
//            outputReachMat<<reachableMatrix[i][j]<<"\t";
//        outputReachMat<<"\n";
//    }
//    outputReachMat.close();
    /**< debug */
    for(int i=0;i!=nodeNum;++i)
    {
        network[i].localReachingCentrality=0;
        for(int j=0;j!=nodeNum;++j)
            network[i].localReachingCentrality+=reachableMatrix[i][j];
        network[i].localReachingCentrality=network[i].localReachingCentrality/nodeNum;
    }
    /**< debug */
//    for(int i=0;i!=nodeNum;++i)
//    {
//        cout<<network[i].localReachingCentrality<<"\t";
//    }
    /**< debug */
    /**< GRC value */
    double LRCmaxValue=network[0].localReachingCentrality;
    for(int i=0;i!=nodeNum;++i)
        if(network[i].localReachingCentrality>LRCmaxValue)
            LRCmaxValue=network[i].localReachingCentrality;
    double GRCvalue=0;
    for(int i=0;i!=nodeNum;++i)
        GRCvalue+=LRCmaxValue-network[i].localReachingCentrality;
    GRCvalue=GRCvalue/nodeNum;
    return GRCvalue;
}
