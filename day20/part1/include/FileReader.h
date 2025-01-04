#include <sstream>
#include <fstream>
#include <algorithm>

#include "Race.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Race readRace();
};