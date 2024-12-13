#include <sstream>
#include <fstream>
#include <algorithm>

#include "Garden.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Garden readgardenMap();
};