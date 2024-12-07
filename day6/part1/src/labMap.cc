#include "../include/labMap.h"

labMap::labMap(stringVector map) {
    this->map = map;
    searchGuard();
    pathCounter = 0;
    guardExited = false;
}

labMap::~labMap() {}

void labMap::searchGuard() {
    bool guardFound = false;
    for(size_t i = 0; i < map.size() && !guardFound; i++) {
        for(size_t j = 0; j < map[i].size() && !guardFound; j++) {
            char g = map[i][j];
            if(g != '.' && g != '#') {
                guardFound = true;
                guardStartingPosition.first = i;
                guardStartingPosition.second = j;

                switch (map[i][j]) {
                    case '>':
                        direction = RIGHT;
                        break;
                    case 'v':
                        direction = DOWN;
                        break;
                    case '<':
                        direction = LEFT;
                        break;
                    case '^':
                        direction = UP;
                        break;
                    default:
                        throw std::runtime_error("Guard position not found.");
                        break;
                }
            }
        }
    }
}

void labMap::startSimulation() {
    
    intPair guardPosition = guardStartingPosition;

    do {
        moveGuard(guardPosition);
    } while (guardPosition != guardStartingPosition && !guardExited);
    printLab(guardPosition);
}

void labMap::moveGuard(intPair& gp) {
    bool canMove = false;
    for(int i = 0; i < 4 && canMove == false; i++) {
        if(i == 3) {
            throw std::runtime_error("Guard can't move.");
        }

        if(!checkMove(gp)){
            direction = static_cast<Direction>((direction + 1) % 4);
        } else {
            canMove = true;
        }
    }

    if(!guardExited) {
        map[gp.first][gp.second] = 'X';

        switch (direction) {
        case RIGHT:
            gp.second++;
            countSteps(gp);
            map[gp.first][gp.second] = '>';
            break;
        case DOWN:
            gp.first++;
            countSteps(gp);
            map[gp.first][gp.second] = 'v';
            break;
        case LEFT:
            gp.second--;
            countSteps(gp);
            map[gp.first][gp.second] = '<';
            break;
        case UP:
            gp.first--;
            countSteps(gp);
            map[gp.first][gp.second] = '^';
            break;
        default:
            throw std::runtime_error("Wrong guard direction.");
            break;
        }
    } else {
        pathCounter++;
    }
}

void labMap::countSteps(const intPair gp) {
    map[gp.first][gp.second] != 'X' ? pathCounter++ : true;
}

bool labMap::checkMove(const intPair gp) {
    bool canMove = true;

    switch (direction) {
        case RIGHT:
            if(gp.second + 1 >= static_cast<int>(map[0].size())) {
                guardExited = true;
                canMove = false;
            } else if(map[gp.first][gp.second + 1] == '#') {
                canMove = false;
            }
            break;
        case DOWN:
            if(gp.first + 1 >= static_cast<int>(map.size())) {
                guardExited = true;
                canMove = false;
            }else if(map[gp.first + 1][gp.second] == '#') {
                canMove = false;
            }
            break;
        case LEFT:
            if(gp.second - 1 < 0) {
                guardExited = true;
                canMove = false;
            }else if(map[gp.first][gp.second - 1] == '#') {
                canMove = false;
            }
            break;
        case UP:
            if(gp.first - 1 < 0) {
                guardExited = true;
                canMove = false;
            }else if(map[gp.first - 1][gp.second] == '#') {
                canMove = false;
            }
            break;
        default:
            throw std::runtime_error("Wrong guard direction.");
            break;
    }

    return canMove;
}

int labMap::getPathCounter() {
    return pathCounter;
}

void labMap::printLab(const intPair gp) {
    system("clear");
    std::cout << "Path steps: " << pathCounter << std::endl;
    int i = gp.first > 15 ? gp.first - 15 : 0;
    int limit = gp.first + 15 > static_cast<int>(map.size()) ? static_cast<Direction>(map.size()) : gp.first + 15;

    for(;i < limit; i++) {
        std::cout << i << "\t" << map[i] << std::endl;
    }
}