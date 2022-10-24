#include "kMeans.h"

KMeans::KMeans(std::vector<NDPoint> *NDPointsVector,int k,int epochs,std::shared_ptr<std::ofstream> fp)
{
    this->NDPointsVector = NDPointsVector;
    this->k = k;
    this->epochs = epochs;
    this->outfile = fp;
}

void KMeans::setCentroidInitially()
{
    std::unordered_set<int> idx_used;
    srand(time(0));
    int n = (*NDPointsVector).size();

    for (int i = 0; i < k;)
    {
        int idx = rand() % n;
        if(idx_used.find(idx)==idx_used.end()){
            centroids.push_back((*NDPointsVector)[idx]);
            idx_used.insert(idx);
            i++;
        }
    }
    
    #ifdef kmeansDebugger
        (*outfile)<<"Selected centroids:\n";
        for(auto x:centroids) {for(auto y:x.ordinates) (*outfile)<<y<<",";(*outfile)<<std::endl;}
    #endif
}

double KMeans::get_distance_bw_points(NDPoint p1,NDPoint p2) const                   
{
    int noOfDimensions = p1.ordinates.size();
    double distance = 0.0;

    for(int i=0;i<noOfDimensions;i++)
            distance += (p1.ordinates[i]-p2.ordinates[i])*(p1.ordinates[i]-p2.ordinates[i]);
   
    return distance;    
}

void KMeans::AssignClusters()
{
    int size = (*NDPointsVector).size();
    for(int i=0;i<size;i++)
    {
        (*NDPointsVector)[i].minDistance = DBL_MAX;

        for(int j=0;j<k;j++)
        {
            double dis = get_distance_bw_points(centroids[j],(*NDPointsVector)[i]);
            if(dis<(*NDPointsVector)[i].minDistance)
            {
                (*NDPointsVector)[i].minDistance = dis;
                (*NDPointsVector)[i].clusterID = j;
            }
        }
        #ifdef kmeansDebugger
            (*outfile)<<"Assigned cluster :"<<(*NDPointsVector)[i].clusterID<<" to point no:"<<i<<std::endl;
        #endif
    }
}

void KMeans::updateCentroids()
{
    std::vector<NDPoint> dimensionsSumCentroid(k);
    std::vector<int> clusterPointsCount(k,0);

    int size = (*NDPointsVector).size();
    int no_of_dimensions=0;

    if(size>0)
    {
        no_of_dimensions = (*NDPointsVector)[0].ordinates.size();
        std::vector<double> ds(no_of_dimensions,0.0);
        for(int i=0;i<k;i++)
            dimensionsSumCentroid[i].ordinates = ds;
    }

    for(int i=0;i<size;i++)
    {
        int cluster_id = (*NDPointsVector)[i].clusterID;
        clusterPointsCount[cluster_id]++;
        for(int j=0;j<no_of_dimensions;j++)
            dimensionsSumCentroid[cluster_id].ordinates[j] += (*NDPointsVector)[i].ordinates[j];
    }

    #ifdef kmeansDebugger
        (*outfile)<<"Updating Centroids:\n";
    #endif
    for(int i=0;i<k;i++)
    {
        for(int d=0;d<no_of_dimensions;d++)
            centroids[i].ordinates[d] = (dimensionsSumCentroid[i].ordinates[d]/clusterPointsCount[i]);
        
        #ifdef kmeansDebugger
            (*outfile)<<"Centroid indx:"<<i<<" -> ";
            for(int d=0;d<no_of_dimensions;d++) (*outfile)<<centroids[i].ordinates[d]<<",";
            (*outfile)<<"\n";
        #endif
    }
}

void KMeans::Run_KMeans()
{
   for(int run=1;run<=epochs;run++)
   {
       if(run==1) setCentroidInitially();
       else updateCentroids();

       AssignClusters();
   }
}

void KMeans::logger()
{
    int size = (*NDPointsVector).size();
    for(int i=0;i<size-1;i++)
        (*outfile)<<(*NDPointsVector)[i].clusterID<<",";
    (*outfile)<<(*NDPointsVector)[size-1].clusterID<<"\n";
}