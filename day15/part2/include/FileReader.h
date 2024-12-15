#include <sstream>
#include <fstream>
#include <algorithm>

#include "Warehouse.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Warehouse readRobots();
};