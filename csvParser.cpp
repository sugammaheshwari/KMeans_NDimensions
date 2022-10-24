#include "csvParser.h"

CsvParser::CsvParser(std::shared_ptr<std::ofstream> fp)
{
  outfile = fp;
}

std::vector<std::string> CsvParser::parse_line(std::string line,char delimiter)
{
    std::stringstream ss(line);
    std::vector<std::string> temp_fields;

    while(ss.good())
    {
        getline(ss,line,delimiter);
        temp_fields.push_back(line);
    }

    return temp_fields;
}

std::vector<std::vector<std::string>> CsvParser::read_and_parse_input_file(std::string file_location,char delimiter)
{
    std::vector<std::vector<std::string>> parsedFileVector;
    std::ifstream file(file_location);
    std::string line;
    
    while(getline(file,line))
        parsedFileVector.push_back(parse_line(line,delimiter));

    #ifdef csvParserDebugger
        (*outfile) << "Printing parsed input file vector\n";
        for(auto l1:parsedFileVector)
        {
            for(auto x:l1) (*outfile)<<x<<",";
            (*outfile)<<"\n";
        }
    #endif

    return parsedFileVector;
}