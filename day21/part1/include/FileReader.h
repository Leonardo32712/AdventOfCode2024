#pragma once

#include <fstream>

#include "StarShip.h"

class fileReader {
private:
    std::ifstream file_;

public:
    fileReader(std::string);
    ~fileReader();

    StarShip readStarShipCodes();
};