#pragma once

#include <fstream>

#include "Race.h"

class fileReader {
private:
    std::ifstream file_;

public:
    fileReader(std::string);
    ~fileReader();

    Race readRace();
};