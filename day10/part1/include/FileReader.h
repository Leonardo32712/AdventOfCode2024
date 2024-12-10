#include <sstream>
#include <fstream>
#include <algorithm>

#include "TopographicMap.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    TopographicMap readTopographicMap();
};