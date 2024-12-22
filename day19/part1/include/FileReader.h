#include <sstream>
#include <fstream>
#include <algorithm>

#include "Onsen.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Onsen readOnsen();
};