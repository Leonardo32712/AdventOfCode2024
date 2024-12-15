#include "../include/Garden.h"

Garden::Garden(stringVector g) : gardenMap(g) {}

Garden::~Garden() {}

int Garden::totalPrice() {
    int totalPrice = 0;

    for(int i = 0; i < static_cast<int>(gardenMap.size()); i++) {
        for(int j = 0; j < static_cast<int>(gardenMap[i].size()); j++) {
            if(std::isupper(gardenMap[i][j])) {
                intPair areaPerimeter(0,0);
                areaPerimeter = exploreRegion(i, j, gardenMap[i][j]);
                totalPrice += (areaPerimeter.first)*(areaPerimeter.second);
            }
        }
    }

    
    // std::cout << std::endl;
    return totalPrice;
}

intPair Garden::exploreRegion(const int i, const int j, const char plant) {
    gardenMap[i][j] = char(tolower(gardenMap[i][j]));
    intPair ap(1,0);
    
    ap.second = checkCorners(i, j, plant);
    
    if(checkPlot(i + 1, j, plant)) {    // GO DOWN
        if(!islower(gardenMap[i + 1][j])) {
            intPair result = exploreRegion(i + 1, j, plant);
            ap.first += result.first;
            ap.second += result.second;
        }
    }

    if(checkPlot(i, j + 1, plant)) {    // GO RIGHT
        if(!islower(gardenMap[i][j + 1])) {
            intPair result = exploreRegion(i, j + 1, plant);
            ap.first += result.first;
            ap.second += result.second;
        }
    }

    if(checkPlot(i - 1, j, plant)) {    // GO UP
        if(!islower(gardenMap[i - 1][j])) {
            intPair result = exploreRegion(i - 1, j, plant);
            ap.first += result.first;
            ap.second += result.second;
        }
    }

    if(checkPlot(i, j - 1, plant)) {    // GO LEFT
        if(!islower(gardenMap[i][j - 1])) {
            intPair result = exploreRegion(i, j - 1, plant);
            ap.first += result.first;
            ap.second += result.second;
        }
    }

    return ap;
}

int Garden::checkCorners(const int i, const int j, const char plant) {
    int perimeter = 0;

    checkCorner(intPair(i,j),intPair(1,1), plant) ? perimeter++ : true;
    checkCorner(intPair(i,j),intPair(1,-1), plant) ? perimeter++ : true;
    checkCorner(intPair(i,j),intPair(-1,1), plant) ? perimeter++ : true;
    checkCorner(intPair(i,j),intPair(-1,-1), plant) ? perimeter++ : true;

    return perimeter;
}

bool Garden::checkCorner(const intPair pos, const intPair cor, const char plant) {
    bool thereIsCorner = false;
    
    if(!checkPlot(pos.first + cor.first, pos.second, plant) && 
       !checkPlot(pos.first, pos.second + cor.second, plant)) {
        thereIsCorner = true;
    }
    
    if(checkPlot(pos.first + cor.first, pos.second, plant) && 
       checkPlot(pos.first, pos.second + cor.second, plant) && 
       !checkPlot(pos.first + cor.first, pos.second + cor.second, plant)) {
        thereIsCorner = true;
    }

    return thereIsCorner;
}

bool Garden::checkPlot(int i, int j, char plant) {
    if(outOfBounds(i,j) || toupper(gardenMap[i][j]) != toupper(plant)) {
        return false;
    } else {
        return true;
    }
}

bool Garden::outOfBounds(int i, int j) {
    return (i < 0 || i >= static_cast<int>(gardenMap.size()) || j < 0 || j >= static_cast<int>(gardenMap[i].size()));
}

void Garden::printGarden() {
    for(int i = 0; i < static_cast<int>(gardenMap.size()); i ++) {
        std::cout << gardenMap[i] << std::endl;
    }
}