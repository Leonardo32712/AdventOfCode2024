#include "../include/Garden.h"

Garden::Garden(stringVector g) : gardenMap(g) {}

Garden::~Garden() {}

int Garden::totalPrice() {
    int totalPrice = 0;

    for(int i = 0; i < static_cast<int>(gardenMap.size()); i++) {
        for(int j = 0; j < static_cast<int>(gardenMap[i].size()); j++) {
            if(std::isupper(gardenMap[i][j])) {
                intPair areaPerimeter(0,0);
                areaPerimeter.first = exploreRegion(i, j, gardenMap[i][j]);
                areaPerimeter.second = calculatePerimeter();

                std::cout << "RESULT (" << char(toupper(gardenMap[i][j])) << ") " << (areaPerimeter.first) << " " << (areaPerimeter.second) << std::endl;
                totalPrice += (areaPerimeter.first)*(areaPerimeter.second);
                perimeterCoords.clear();
            }
        }
    }

    
    // std::cout << std::endl;
    return totalPrice;
}

int Garden::calculatePerimeter() {
    int perimeter = 2;
    int growth[] = {0, 0, 0, 0}; // down, right, up, left

    int x = -1;
    int y = -1;
    for (const auto& coord : perimeterCoords) {
        if(x != -1 && y != -1) {
            if(coord.first - x > 0) {
                growth[0] = coord.first - x;
            }

            if(coord.second - y > 0) {
                growth[1] = coord.second - y;
            }

            if(coord.first - x < 0) {
                growth[2] = coord.first - x;
            }

            if(coord.second - y < 0) {
                growth[3] = coord.second - y;
            }
        }

        x = coord.first;
        y = coord.second;
        std::cout << "(" << coord.first << "," << coord.second << ") ";
        std::cout << growth[0] << " " << growth[1] << " " << growth[2] << " " << growth[3] << std::endl;
    }

    return perimeter;
}

int Garden::exploreRegion(const int i, const int j, const char plant) {
    gardenMap[i][j] = char(tolower(gardenMap[i][j]));
    int area = 1;
    
    if(checkPlot(i + 1, j, plant)) {    // GO DOWN
        if(!islower(gardenMap[i + 1][j])) {
            area += exploreRegion(i + 1, j, plant);
        }
    } else {
        perimeterCoords.emplace(intPair(i,j));
        //std::cout << plant << " (" << i + 1 << "," << j + 1 << "): DOWN" << std::endl;
    }

    if(checkPlot(i, j + 1, plant)) {    // GO RIGHT
        if(!islower(gardenMap[i][j + 1])) {
            area += exploreRegion(i, j + 1, plant);
        }
    } else {
        perimeterCoords.emplace(intPair(i,j));
        //std::cout << plant << " (" << i + 1 << "," << j + 1 << "): RIGHT" << std::endl;
    }

    if(checkPlot(i - 1, j, plant)) {    // GO UP
        if(!islower(gardenMap[i - 1][j])) {
            area += exploreRegion(i - 1, j, plant);
        }
    } else {
        perimeterCoords.emplace(intPair(i,j));
        //std::cout << plant << " (" << i + 1 << "," << j + 1 << "): UP" << std::endl;
    }

    if(checkPlot(i, j - 1, plant)) {    // GO LEFT
        if(!islower(gardenMap[i][j - 1])) {
            area += exploreRegion(i, j - 1, plant);
        }
    } else {
        perimeterCoords.emplace(intPair(i,j));
        //std::cout << plant << " (" << i + 1 << "," << j + 1 << "): LEFT" << std::endl;
    }

    return area;
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
        // std::cout << gardenMap[i] << std::endl;
    }
}