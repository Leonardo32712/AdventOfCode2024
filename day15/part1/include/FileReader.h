#include <sstream>
#include <fstream>
#include <algorithm>

#include "RobotSimulator.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    RobotSimulator readRobots();
};