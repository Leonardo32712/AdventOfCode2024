#include <iostream>

#include "../include/Race.h"

Race::Race(std::vector<std::string> map) : raceMap(map) {
    findPathStartAndEnd();
    if(pathStart == intPair({-1,-1})) {
        throw std::runtime_error("Start not found.");
    }
    savePathData(pathStart);
}

Race::~Race() {}

void Race::findPathStartAndEnd() {
    for(size_t i = 0; i < raceMap.size(); i++) {
        for(size_t j = 0; j < raceMap[i].size(); j++) {
            if(raceMap[i][j] == 'S') { 
                pathStart = {i,j}; 
            } else if(raceMap[i][j] == 'E') {
                pathEnd = {i,j};
            }
        }
    }
}

void Race::savePathData(intPair pathStart) {
    intPair currentCoords = pathStart;
    coordsSet visited;
    long picoSeconds = 0;
    bool noExit = false;

    while(!noExit) {
        noExit = true;

        visited.insert(currentCoords);
        for(int rotation = 0; rotation < 4 && noExit; rotation++) {
            Direction dir = static_cast<Direction>(rotation);
            intPair nextCoords = moveCoord(currentCoords, dir);
            if(canMove(currentCoords, dir) && visited.find(nextCoords) == visited.end()) {
                path[currentCoords] = picoSeconds;
                picoSeconds++;
                currentCoords = nextCoords;
                noExit = false;
            }
        }
    }

    path[currentCoords] = picoSeconds;
}

int Race::getShortCutsCountByMinTimeSaved(int minTimeSave) {
    ShortCutSet scs = getPathShortCuts();
    int shortCutCounter = 0;

    for(ShortCut sc: scs) {
        if(sc.timeDifference >= minTimeSave) {
            shortCutCounter++;
        }
    }

    return shortCutCounter;
}

ShortCutSet Race::getPathShortCuts() {
    ShortCutSet shortCuts;

    for(std::pair<intPair,int> pathCell: path) {
        intPair coords = pathCell.first;
        for(int radius = 2; radius <= 20; radius++) {
            exploreRegion(coords, radius, shortCuts);
        }
    }

    return shortCuts;
}

void Race::exploreRegion(intPair origin, int radius, ShortCutSet& shortCuts) {
    for(int i = -radius; i <= radius; i++) {
        for(int j = abs(i) - radius; j <= radius - abs(i); j++) {
            intPair destiny = intPair({origin.first + i, origin.second + j});
            exploreShortCut(origin, destiny, shortCuts);
        }
    }
}

void Race::exploreShortCut(intPair origin, intPair destiny, ShortCutSet& shortCuts) {
    auto originTimeIt = path.find(origin);
    auto destinyTimeIt = path.find(destiny);

    if (originTimeIt == path.end() || destinyTimeIt == path.end()) { return; }

    long originTime = originTimeIt->second;
    long destinyTime = destinyTimeIt->second;

    int distance = abs(origin.first - destiny.first) + abs(origin.second - destiny.second);

    if (destinyTime <= originTime + distance) { return; }

    shortCuts.insert(ShortCut({origin, destiny, destinyTime - originTime - distance}));
}

intPair Race::moveCoord(intPair coords, Direction d) {
    switch (d) {
        case UP: return intPair(coords.first - 1, coords.second);
        case RIGHT: return intPair(coords.first, coords.second + 1);
        case DOWN: return intPair(coords.first + 1, coords.second);
        case LEFT: return intPair(coords.first, coords.second - 1);
    }
    return coords;
}
bool Race::canMove(intPair coords, Direction dir) {
    return canMoveTo(moveCoord(coords, dir));
}

bool Race::canMoveTo(intPair coords) {
    return !outOfBounds(coords) && !isWall(coords);
}

bool Race::outOfBounds(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(raceMap.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(raceMap[0].size()));
}

bool Race::isWall(intPair pos) {
    return raceMap[pos.first][pos.second] == '#';
}

void Race::printShortCutsByTime() {
    ShortCutSet shortCuts = getPathShortCuts();
    std::map<int, long> times;

    for(ShortCut s : shortCuts) {
        std::cout << "[(" << s.firstCoord.first << "," << s.firstCoord.second << "),(" << s.secondCoord.first << "," << s.secondCoord.second << ")]: " << s.timeDifference << std::endl;
    }

    for(ShortCut sc: shortCuts) {
        if(times.find(sc.timeDifference) == times.end()) {
            int time = sc.timeDifference;
            times[time] = 0;
            for(ShortCut sc: shortCuts) {
                if(sc.timeDifference == time) {
                    times[time]++;
                }
            }
        }
    }

    for(auto t: times) {
        std::cout << t.first << ": " << t.second << std::endl;
    }
}

void Race::printMap() {
    std::cout << std::endl << "  ";
    for(size_t i = 0; i < raceMap[0].size(); i++) {
        std::cout << i % 10 << " ";
    }
    std::cout << std::endl;
    for(size_t i = 0; i < raceMap.size(); i++) {
        std::cout << i % 10 << " ";
        for(size_t j = 0; j < raceMap[i].size(); j++) {
            std::cout << raceMap[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
}