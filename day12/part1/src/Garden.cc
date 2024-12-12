#include "../include/Garden.h"

Garden::Garden(stringVector g) : gardenMap(g) {}

Garden::~Garden() {}

int Garden::totalPrice() {
    int totalPrice = 0;

    for(int i = 0; i < static_cast<int>(gardenMap.size()); i++) {
        for(int j = 0; j < static_cast<int>(gardenMap[i].size()); j++) {
            if(std::isupper(gardenMap[i][j])) {
                areaPerimeter ap(0,0);
                exploreRegion(i, j, gardenMap[i][j], ap);
                totalPrice += ap.first*ap.second;
            }
        }
    }

    return totalPrice;
}

void Garden::exploreRegion(int i, int j, char plant, areaPerimeter& ap) {
    gardenMap[i][j] = std::tolower(gardenMap[i][j]);
    ap.first++;
    checkPlot(i + 1, j, plant, ap);
    checkPlot(i, j + 1, plant, ap);
    checkPlot(i, j - 1, plant, ap);
    checkPlot(i - 1, j, plant, ap);
}

void Garden::checkPlot(int i, int j, char plant, areaPerimeter& ap) {
    if (!outOfBounds(i, j)) {
        if(gardenMap[i][j] != std::tolower(plant)) {
            if (gardenMap[i][j] != plant) {
                ap.second++;
            } else {
                exploreRegion(i, j, plant, ap);
            }
        }
    } else {
        ap.second++;
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