#include "structures.h"
#include <fstream>
#include <float.h>
#include <unordered_set>

class KMeans{
    private:
        int epochs,k;
        std::vector<NDPoint> *NDPointsVector,centroids;
        std::shared_ptr<std::ofstream> outfile;

    public:
        KMeans(std::vector<NDPoint> *NDPointsVector,int k,int epochs,std::shared_ptr<std::ofstream> fp);
        void setCentroidInitially();
        double get_distance_bw_points(NDPoint p1,NDPoint p2) const;                      // can use const keyword as no need to change the value of variable
        void AssignClusters();
        void updateCentroids();
        void Run_KMeans();
        void logger();
};