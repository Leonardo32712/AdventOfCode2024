#include "../include/Warehouse.h"

Warehouse::Warehouse(std::vector<std::string> map, std::vector<Direction> r) : 
    wareHouseMap(map), 
    robot(r, findRobot()) {}

Warehouse::~Warehouse() {}

void Warehouse::doubleWide() {
    std::vector<std::string> newMap({});
    std::string newLine("");

    for(size_t i = 0; i < wareHouseMap.size(); i++) {
        for(size_t j = 0; j < wareHouseMap[i].size(); j++) {
            if(wareHouseMap[i][j] == '#') {
                newLine += "##";
            } else if(wareHouseMap[i][j] == '.') {
                newLine += "..";
            } else if(wareHouseMap[i][j] == 'O') {
                newLine += "[]";
            } else if(wareHouseMap[i][j] == '@') {
                newLine += "@.";
            }
        }
        newMap.push_back(newLine);
        newLine = "";
    }

    wareHouseMap = newMap;
    intPair oldRobotPos = robot.getPosition();
    oldRobotPos.second *= 2;
    robot.setPosition(oldRobotPos);
}

intPair Warehouse::findRobot() {
    intPair robotPos(-1,-1);
    for(size_t i = 0; i < wareHouseMap.size(); i++) {
        for(size_t j = 0; j < wareHouseMap[i].size(); j++) {
            if(wareHouseMap[i][j] == '@') {
                robotPos = intPair(i,j);
            }
        }
    }
    
    if(robotPos == intPair(-1,-1)) {
        throw std::runtime_error("Robot not found.");
    }

    return robotPos;
}

void Warehouse::simulateMove() {
    Direction robotMovement = NONE;
    do {
        robotMovement = robot.nextMove();
        intPair robotPos = robot.getPosition();
        if(robotMovement != NONE && checkMove(robotPos, robotMovement)) {
            wareHouseMap[robotPos.first][robotPos.second] = '.';
            robotPos = getNextStep(robotPos, robotMovement);
            robot.setPosition(robotPos);
            wareHouseMap[robotPos.first][robotPos.second] = '@';
        }
        system("clear");
        printWarehouse();
    } while(robotMovement != NONE);
}

long Warehouse::getSumGPS() {
    long sumGPS = 0;
    for(size_t i = 1; i < wareHouseMap.size() - 1; i++) {
        for(size_t j = 2; j < wareHouseMap[i].size() - 2; j++) {
            if(wareHouseMap[i][j] == '[') {
                sumGPS += (i * 100) + j;
            }
        }
    }
    return sumGPS;
}

bool Warehouse::checkMove(intPair pos, Direction d) {
    intPair nextPos = getNextStep(pos, d);
    if(outOfBounds(nextPos)) {
        return false;
    }

    if(wareHouseMap[nextPos.first][nextPos.second] == '.') {
        return true;
    } else if (wareHouseMap[nextPos.first][nextPos.second] == ']' && (d == UP || d == DOWN)) {
        if(checkMoveBox(intPair(nextPos.first, nextPos.second - 1), nextPos, d, false)) {
            return checkMoveBox(intPair(nextPos.first, nextPos.second - 1), nextPos, d, true);
        }
    } else if (wareHouseMap[nextPos.first][nextPos.second] == '[' && (d == UP || d == DOWN)) {
        if(checkMoveBox(nextPos, intPair(nextPos.first, nextPos.second + 1), d, false)) {
            return checkMoveBox(nextPos, intPair(nextPos.first, nextPos.second + 1), d, true);
        }

    } else if (wareHouseMap[nextPos.first][nextPos.second] == ']' && d == LEFT) {
        if(checkMoveBox(intPair(nextPos.first, nextPos.second - 1), nextPos, d, false)) {
            return checkMoveBox(intPair(nextPos.first, nextPos.second - 1), nextPos, d, true);
        }

    } else if ( wareHouseMap[nextPos.first][nextPos.second] == '[' && d == RIGHT) {
        if(checkMoveBox(nextPos, intPair(nextPos.first, nextPos.second + 1), d, false)) {
            return checkMoveBox(nextPos, intPair(nextPos.first, nextPos.second + 1), d, true);
        }
    }
        
    return false;
}

bool Warehouse::checkMoveBox(intPair pos1, intPair pos2, Direction d, bool save) {
    intPair nextPos1 = getNextStep(pos1, d);
    intPair nextPos2 = getNextStep(pos2, d);

    if(outOfBounds(nextPos1) || outOfBounds(nextPos2)) {
        return false;
    } else if ( wareHouseMap[nextPos1.first][nextPos1.second] == '#' ||
                wareHouseMap[nextPos2.first][nextPos2.second] == '#') {
        return false;
    }

    if( (wareHouseMap[nextPos1.first][nextPos1.second] == '.' && d == LEFT) ||
        (wareHouseMap[nextPos2.first][nextPos2.second] == '.' && d == RIGHT) || 
        (wareHouseMap[nextPos1.first][nextPos1.second] == '.' && 
         wareHouseMap[nextPos2.first][nextPos2.second] == '.')) { 
        if(save) { saveBoxMove(nextPos1, nextPos2, pos1, pos2, d); }         
        return true;
    } else if (wareHouseMap[nextPos1.first][nextPos1.second] == '[' && (d == UP || d == DOWN)) {
        if(checkMoveBox(nextPos1, nextPos2, d, save)) {
            if(save) { saveBoxMove(nextPos1, nextPos2, pos1, pos2, d); } 
            return true;
        } else {
            return false;
        }
    } else if (wareHouseMap[nextPos1.first][nextPos1.second] == ']' && d == LEFT) {
        if(checkMoveBox(intPair(nextPos1.first, nextPos1.second - 1), nextPos1, d, save)) {
            if(save) { saveBoxMove(nextPos1, nextPos2, pos1, pos2, d); } 
            return true;
        } else {
            return false;
        }
    } else if ( wareHouseMap[nextPos2.first][nextPos2.second] == '[' && d == RIGHT) {
        if(checkMoveBox(nextPos2, intPair(nextPos2.first, nextPos2.second + 1), d, save)) {
            if(save) { saveBoxMove(nextPos1, nextPos2, pos1, pos2, d); } 
            return true;
        } else {
            return false;
        }
    }
    
    if (wareHouseMap[nextPos1.first][nextPos1.second] == ']' && (d == UP || d == DOWN)) {
        if(!checkMoveBox(intPair(nextPos1.first, nextPos1.second - 1), nextPos1, d, save)) {
            return false;
        }
    }

    if (wareHouseMap[nextPos2.first][nextPos2.second] == '[' && (d == UP || d == DOWN)) {
        if(!checkMoveBox(nextPos2, intPair(nextPos2.first, nextPos2.second + 1), d, save)) {
            return false;
        }
    }
    
    if(save) { saveBoxMove(nextPos1, nextPos2, pos1, pos2, d); } 
    return true;
}

void Warehouse::saveBoxMove(intPair nextPos1, intPair nextPos2, intPair pos1, intPair pos2, Direction d) {
    switch (d) {
        case LEFT:
            wareHouseMap[nextPos1.first][nextPos1.second] = '[';
            wareHouseMap[nextPos2.first][nextPos2.second] = ']';
            wareHouseMap[pos2.first][pos2.second] = '.';
            break;
        case RIGHT:
            wareHouseMap[nextPos1.first][nextPos1.second] = '[';
            wareHouseMap[nextPos2.first][nextPos2.second] = ']';
            wareHouseMap[pos1.first][pos1.second] = '.';
            break;
        default:
            wareHouseMap[nextPos1.first][nextPos1.second] = '[';
            wareHouseMap[nextPos2.first][nextPos2.second] = ']';
            wareHouseMap[pos1.first][pos1.second] = '.';
            wareHouseMap[pos2.first][pos2.second] = '.';
            break;
    }
}

intPair Warehouse::getNextStep(intPair pos, Direction d) {
    switch (d) {
        case 1:
            return intPair(pos.first - 1, pos.second);
        case 2:
            return intPair(pos.first, pos.second + 1);
        case 3:
            return intPair(pos.first + 1, pos.second);
        case 4:
            return intPair(pos.first, pos.second - 1);
        default:
            return pos;
    }
}

bool Warehouse::outOfBounds(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(wareHouseMap.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(wareHouseMap[0].size()));
}

void Warehouse::printWarehouse() {
    for(std::string line : wareHouseMap) {
        for(char c : line) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;

    //robot.printRobotProgram();
}