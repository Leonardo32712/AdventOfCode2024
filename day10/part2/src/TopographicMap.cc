#include "../include/TopographicMap.h"

TopographicMap::TopographicMap(intMatrix m) {
    this->map = m;
}

TopographicMap::~TopographicMap() {}

long TopographicMap::getRatingSum() {
    long sumRating = 0;
    findTrailHeads();
    
    for(int sum : trailHeads) {
        sumRating += sum;
    }

    return sumRating;
}

void TopographicMap::findTrailHeads() {
    intVector th({});

    for(size_t i = 0; i < map.size(); i ++) {
        for(size_t j = 0; j < map[i].size(); j ++) {
            if(map[i][j] == 0) {
                int sum = 0;
                checkNextStep(i,j,sum);
                if(sum > 0) {
                    th.push_back(sum);
                }
            }
        }
    }

    trailHeads = th;
} 

bool TopographicMap::checkNextStep(size_t i, size_t j, int& sum) {
    if(map[i][j] == 9) {
        sum++;
        return true;
    }

    if(!outOfBounds(i + 1, j) && map[i + 1][j] == map[i][j] + 1) {
        checkNextStep(i + 1, j, sum);
    }

    if(!outOfBounds(i - 1, j) && map[i - 1][j] == map[i][j] + 1) {
        checkNextStep(i - 1, j, sum);
    }

    if(!outOfBounds(i, j + 1) && map[i][j + 1] == map[i][j] + 1) {
        checkNextStep(i, j + 1, sum);
    }

    if(!outOfBounds(i, j - 1) && map[i][j - 1] == map[i][j] + 1) {
        checkNextStep(i, j - 1, sum);
    }

    return false;
}


bool TopographicMap::outOfBounds(size_t i, size_t j) {
    return (i < 0 || i >= map.size() || j < 0 || i >= map[j].size());
}

void TopographicMap::printMap() {
    for(size_t i = 0; i < map.size(); i ++) {
        for(size_t j = 0; j < map[i].size(); j ++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}