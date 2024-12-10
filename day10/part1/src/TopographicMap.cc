#include "../include/TopographicMap.h"

TopographicMap::TopographicMap(intMatrix m) {
    this->map = m;
}

TopographicMap::~TopographicMap() {}

long TopographicMap::getScoreSum() {
    long sumScore = 0;
    findTrailHeads();
    
    for(int sum : trailHeads) {
        sumScore += sum;
    }

    return sumScore;
}

void TopographicMap::findTrailHeads() {
    intVector th({});
    coordVector nr({});

    for(size_t i = 0; i < map.size(); i ++) {
        for(size_t j = 0; j < map[i].size(); j ++) {
            if(map[i][j] == 0) {
                int sum = 0;
                checkNextStep(i,j,sum, nr);
                if(sum > 0) {
                    th.push_back(sum);
                }
            }
            nr.clear();
        }
    }

    trailHeads = th;
} 

bool TopographicMap::checkNextStep(size_t i, size_t j, int& sum, coordVector& nr) {
    if(map[i][j] == 9 && !nineReached(i,j,nr)) {
        sum++;
        nr.push_back(coord(i,j));
        return true;
    }

    if(!outOfBounds(i + 1, j) && map[i + 1][j] == map[i][j] + 1) {
        checkNextStep(i + 1, j, sum, nr);
    }

    if(!outOfBounds(i - 1, j) && map[i - 1][j] == map[i][j] + 1) {
        checkNextStep(i - 1, j, sum, nr);
    }

    if(!outOfBounds(i, j + 1) && map[i][j + 1] == map[i][j] + 1) {
        checkNextStep(i, j + 1, sum, nr);
    }

    if(!outOfBounds(i, j - 1) && map[i][j - 1] == map[i][j] + 1) {
        checkNextStep(i, j - 1, sum, nr);
    }

    return false;
}

bool TopographicMap::nineReached(const size_t& i, const size_t& j, const coordVector& nr) {
    for(coord c : nr) {
        if(c.first == i && c.second == j) {
            return true;
        }
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