#include "../include/labMap.h"

labMap::labMap(stringVector map) {
    resetMap(map);
}

labMap::~labMap() {}

intPair labMap::searchGuardPosition() {
    for(size_t i = 0; i < map.size(); i++) {
        for(size_t j = 0; j < map[i].size(); j++) {
            char g = map[i][j];
            if(g != '.' && g != '#') {
                return intPair(i,j);
            }
        }
    }
    return intPair(1,1);
}

Direction labMap::searchGuardDirection(const intPair gp) {
    switch (map[gp.first][gp.second]) {
        case '>': return RIGHT;
        case 'v': return DOWN;
        case '<': return LEFT;
        case '^': return UP;
        default: throw std::runtime_error("Guard position not found.");
    }
}

void labMap::resetMap(const stringVector map) {
    this->map = map;
    this->guardStartingPosition = searchGuardPosition();
    this->guardDirection = searchGuardDirection(guardStartingPosition);
    loopfound = false;
    guardLeavingMap = false;
}

stringVector labMap::getMap() {
    return map;
}

bool labMap::startSimulation(int i, int j) {
    if(map[i][j] != '.') {
        loopfound = false;
    } else {
        map[i][j] = '#';
        intPair guardPosition = guardStartingPosition;
        do {
            moveGuard(guardPosition);
        } while (!guardLeavingMap && !loopfound);
    }

    return loopfound;
}

void labMap::moveGuard(intPair& gp) {
    adjustGuardRotation(gp);

    if(!guardLeavingMap && !loopfound) {
        gp = getNextPosition(gp);
        map[gp.first][gp.second] = getDirectionChar();
    }
}

void labMap::adjustGuardRotation(const intPair gp) {
    bool canMove = false;
    for(int i = 0; i < 4 && !canMove && !guardLeavingMap && !loopfound; i++) {
        if(i == 3) {
            throw std::runtime_error("Guard can't move.");
        }

        if(!checkNextMove(gp)){
            guardDirection = static_cast<Direction>((guardDirection + 1) % 4);
        } else {
            canMove = true;
        }
    }
}

char labMap::getDirectionChar() {
    switch (guardDirection) {
        case RIGHT: return '>';
        case DOWN: return 'v';
        case LEFT: return '<';
        case UP: return '^';
        default: throw std::runtime_error("Wrong guard direction.");
    }
}

bool labMap::checkNextMove(const intPair gp) {
    intPair nextPosition = getNextPosition(gp);

    if (isOutOfBounds(nextPosition)) {
        guardLeavingMap = true;
        return false;
    }

    char cell = map[nextPosition.first][nextPosition.second];

    return evaluateCell(cell);
}

intPair labMap::getNextPosition(const intPair& gp) const {
    switch (guardDirection) {
        case RIGHT: return {gp.first, gp.second + 1};
        case DOWN:  return {gp.first + 1, gp.second};
        case LEFT:  return {gp.first, gp.second - 1};
        case UP:    return {gp.first - 1, gp.second};
        default: throw std::runtime_error("Wrong guard direction.");
    }
}

bool labMap::isOutOfBounds(const intPair& pos) const {
    return pos.first < 0 || pos.first >= static_cast<int>(map.size()) ||
           pos.second < 0 || pos.second >= static_cast<int>(map[0].size());
}

bool labMap::evaluateCell(char cell) {
    if (cell == '#') {
        return false;
    }
    if ((guardDirection == RIGHT && cell == '>') || 
        (guardDirection == DOWN && cell == 'v') ||
        (guardDirection == LEFT && cell == '<') ||
        (guardDirection == UP && cell == '^')) {
        loopfound = true;
    }
    return true;
}


void labMap::printLab(const intPair gp) {
    system("clear");
    int i = gp.first > 15 ? gp.first - 15 : 0;
    int limit = gp.first + 15 > static_cast<int>(map.size()) ? static_cast<Direction>(map.size()) : gp.first + 15;

    for(;i < limit; i++) {
        std::cout << i << "\t" << map[i] << std::endl;
    }
}