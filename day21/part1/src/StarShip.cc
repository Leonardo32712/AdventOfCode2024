#include <iostream>

#include "../include/StarShip.h"

StarShip::StarShip(std::vector<std::string> c) {
    codes = c;
}

StarShip::~StarShip() {}

void StarShip::printCodes() {
    for(std::string c: codes) {
        std::cout << c << std::endl;
    }
}