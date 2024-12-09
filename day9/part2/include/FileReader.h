#include <sstream>
#include <fstream>
#include <algorithm>

#include "DiskMap.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    DiskMap readDiskMap();
};

