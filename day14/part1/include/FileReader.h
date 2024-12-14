#include <sstream>
#include <fstream>
#include <algorithm>

#include "Robot.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    std::vector<Robot> readRobots();
};