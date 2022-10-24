#include "csvParser.h"
#include "structures.h"

class CsvParserToNDPoint : public CsvParser{

    public:
        CsvParserToNDPoint(std::shared_ptr<std::ofstream> fp):CsvParser(fp){};
        std::vector<NDPoint> read_and_parse_input_file_to_NDPoint(std::string file_location,char delimiter);
};