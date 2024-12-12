#include "../include/Garden.h"

Garden::Garden(stringVector g) {
    this->gardenMap = g;
}

Garden::~Garden() {}

bool Garden::outOfBounds(size_t i, size_t j) {
    return (i < 0 || i >= gardenMap.size() || j < 0 || i >= gardenMap[j].size());
}

void Garden::printGarden() {
    for(size_t i = 0; i < gardenMap.size(); i ++) {
        std::cout << gardenMap[i] << std::endl;
    }
}