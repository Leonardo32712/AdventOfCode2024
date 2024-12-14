#include <sstream>
#include <fstream>
#include <algorithm>

#include "ClawMachine.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    std::vector<ClawMachine> readClawMachines();
};