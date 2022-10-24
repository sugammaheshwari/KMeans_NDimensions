#include <iostream>
#include <memory>
#include "csvParserToNDPoint.h"
#include "kMeans.h"

int main(int argc,char *argv[])
{
    if(argc<3)
    {
        std::cout<<"Please enter the arguments : ND-Point File location,K value and epochs to proceed\n";
        return 0;
    }

    std::string ndPointInputFile = argv[1];
    int K = atoi(argv[2]);
    int epochs = 5;

    std::shared_ptr<std::ofstream> outfile = std::make_shared<std::ofstream>("KMeans_Clustering_Output.csv");

    CsvParserToNDPoint parser = CsvParserToNDPoint(outfile);
    std::vector<NDPoint> NDPointsVector = parser.read_and_parse_input_file_to_NDPoint(ndPointInputFile,',');

    KMeans km(&NDPointsVector,K,epochs,outfile);
    km.Run_KMeans();
    km.logger();

    return 0;
}