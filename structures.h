#ifndef _structures
#define _structures

#include<vector>
#include<float.h>

struct NDPoint{
    std::vector<double> ordinates;
    int clusterID;
    double minDistance;

    NDPoint()
    {
        for(auto &ord:ordinates) ord = 0.0;
        clusterID = -1;
        minDistance = DBL_MAX;
    }
};

#endif