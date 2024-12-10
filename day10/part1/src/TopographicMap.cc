#include "../include/TopographicMap.h"

TopographicMap::TopographicMap(intMatrix m) {
    this->map = m;
}

TopographicMap::~TopographicMap() {}

long long TopographicMap::getScoreSum() {
    long long checkSum = 0;

    return checkSum;
}

void TopographicMap::printMap() {
    for(size_t i = 0; i < map.size(); i ++) {
       for(size_t j = 0; j < map[i].size(); j ++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}