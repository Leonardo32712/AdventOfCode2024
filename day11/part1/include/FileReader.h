#include <sstream>
#include <fstream>
#include <algorithm>

#include "StoneArrange.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    StoneArrange readStoneArrange();
};