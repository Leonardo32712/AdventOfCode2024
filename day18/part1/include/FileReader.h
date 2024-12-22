#include <sstream>
#include <fstream>
#include <algorithm>

#include "Computer.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Computer readPC();
};