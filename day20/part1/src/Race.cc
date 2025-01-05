#include <iostream>

#include "../include/Race.h"

Race::Race(std::vector<std::string> map) : raceMap(map) {
    intPair pathStart = findPathStart();
    if(pathStart == intPair({-1,-1})) {
        throw std::runtime_error("Start not found.");
    }
    savePathData(pathStart);
}

Race::~Race() {}

intPair Race::findPathStart() {
    for(size_t i = 0; i < raceMap.size(); i++) {
        for(size_t j = 0; j < raceMap[i].size(); j++) {
            if(raceMap[i][j] == 'S') { 
                return {i,j}; 
            }
        }
    }
    return {-1,-1};
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
        exploreShortCut(coords, {coords.first, coords.second - 2}, shortCuts);
        exploreShortCut(coords, {coords.first - 2, coords.second}, shortCuts);
        exploreShortCut(coords, {coords.first, coords.second + 2}, shortCuts);
        exploreShortCut(coords, {coords.first + 2, coords.second}, shortCuts);
    }

    return shortCuts;
}

void Race::exploreShortCut(intPair origin, intPair destiny, ShortCutSet& shortCuts) {
    auto originTimeIt = path.find(origin);
    auto destinyTimeIt = path.find(destiny);

    if (originTimeIt == path.end() || destinyTimeIt == path.end()) { return; }

    long originTime = originTimeIt->second;
    long destinyTime = destinyTimeIt->second;

    if (destinyTime <= originTime + 2) { return; }

    int midX = (origin.first + destiny.first) / 2;
    int midY = (origin.second + destiny.second) / 2;
    intPair midCoords = {midX, midY};

    shortCuts.insert(ShortCut({midCoords, destiny, destinyTime - originTime - 2}));
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