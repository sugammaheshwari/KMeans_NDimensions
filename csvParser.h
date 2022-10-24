
#include<sstream>
#include<fstream>
#include<vector>
#include<memory>

class CsvParser{

    private:
        std::shared_ptr<std::ofstream> outfile;

    public:
        CsvParser(std::shared_ptr<std::ofstream> fp);
        std::vector<std::string> parse_line(std::string line,char delimiter);
        std::vector<std::vector<std::string>> read_and_parse_input_file(std::string file_location,char delimiter);
};