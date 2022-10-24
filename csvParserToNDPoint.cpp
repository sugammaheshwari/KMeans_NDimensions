#include "csvParserToNDPoint.h"

std::vector<NDPoint> CsvParserToNDPoint::read_and_parse_input_file_to_NDPoint(std::string file_location,char delimiter)
{
  std::vector<NDPoint> parsedNDPointVector;

  std::vector<std::vector<std::string>> parsedFileVectorString = read_and_parse_input_file(file_location,delimiter);

  for(auto _ordinates:parsedFileVectorString)
  {
    NDPoint point = NDPoint();
    for(int i=0;i<_ordinates.size();i++)
      point.ordinates.push_back(stod(_ordinates[i]));
    parsedNDPointVector.push_back(point);
  }
  
  return parsedNDPointVector;
}