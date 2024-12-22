#include "../include/Onsen.h"

Onsen::Onsen(stringVector p, stringVector d) : 
        patterns(p), 
        desings(d) {}

Onsen::~Onsen() {}

void Onsen::printOnsen() {
    for(std::string p : patterns) {
        std::cout << p << ", ";
    }

    std::cout << std::endl << std::endl;

    for(std::string d : desings) {
        std::cout << d << std::endl;
    }
}