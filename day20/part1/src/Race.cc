#include "../include/Race.h"

Race::Race(std::vector<std::string> map) : raceMap(map) {
    shortCutLessScore = 0;
    pathStart = findPathStart();
    savePathTimes();
}

Race::~Race() {}

void Race::savePathTimes() {
    intPair currentCoords = pathStart;
    coordsSet visited;
    long picoSeconds = 0;
    bool noExit = false;

    while(!noExit) {
        Direction dir = RIGHT;
        noExit = true;

        visited.insert(currentCoords);
        for(int rotation = 0; rotation < 4 && noExit; rotation++) {
            intPair nextCoords = moveCoord(currentCoords, dir);
            if(canMove(currentCoords, dir) && visited.find(nextCoords) == visited.end()) {
                noExit = false;
                pathTimes[currentCoords] = picoSeconds;
                path.push_back(currentCoords);
                picoSeconds++;
                currentCoords = nextCoords;
            } else {
                rotateDirectionRight(dir, 1);
            }
        }
    }

    path.push_back(currentCoords);
    pathTimes[currentCoords] = picoSeconds;
    shortCutLessScore = picoSeconds;

    //std::cout << "PATH SAVED" << std::endl;
}

intPair Race::findPathStart() {
    for(size_t i = 0; i < raceMap.size(); i++) {
        for(size_t j = 0; j < raceMap[i].size(); j++) {
            if(raceMap[i][j] == 'S') { 
                //std::cout << "START FOUND" << std::endl;
                return {i,j}; 
            }
        }
    }
    return {-1,-1};
}

int Race::getShortCutsByMinTimeSave(int minTimeSave) {
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

    std::cout << "FINDING SHORTCUTS";
    for(intPair coords: path) {
        std::cout << "." << std::flush;
        exploreShortCut(coords, {coords.first, coords.second - 2}, shortCuts);
        exploreShortCut(coords, {coords.first - 2, coords.second}, shortCuts);
        exploreShortCut(coords, {coords.first, coords.second + 2}, shortCuts);
        exploreShortCut(coords, {coords.first + 2, coords.second}, shortCuts);
    }

    // for(ShortCut s : shortCuts) {
    //     std::cout << "[(" << s.firstCoord.first << "," << s.firstCoord.second << "),(" << s.secondCoord.first << "," << s.secondCoord.second << ")]: " << s.timeDifference << std::endl;
    // }
    // printShortCutsByTime(shortCuts);

    return shortCuts;
}

void Race::exploreShortCut(intPair origin, intPair destiny, ShortCutSet& shortCuts) {
    if(pathTimes.find(origin) != pathTimes.end() && pathTimes.find(destiny) != pathTimes.end()) {
        if(pathTimes[destiny] > pathTimes[origin] + 2 && canMove(destiny)) {
            int firstCoord = origin.first + ((destiny.first - origin.first)/2);
            int secondCoord = origin.second + ((destiny.second - origin.second)/2);
            intPair firstCoords = intPair({firstCoord, secondCoord});
            shortCuts.insert(ShortCut({firstCoords, destiny, pathTimes[destiny] - pathTimes[origin] - 2}));
        }
    }
}

// void Race::exploreShortCut(coordsVector shortCutCoords, ShortCutSet& shortCuts, const coordsSet& visited) {
//     coordsSet explored = visited;
//     Direction dir = RIGHT;
//     intPair coords;
//     coords = shortCutCoords.back();
//     explored.insert(coords);

//     // std::cout << shortCutCoords.size() << " | (" << coords.first << "," << coords.second << ") " << std::endl;
//     // std::cin.get();
//     int shortCutTime = pathTimes[shortCutCoords[0]] + (shortCutCoords.size()) - 1;
//     ShortCut shortCut = {shortCutCoords[1], shortCutCoords[2], pathTimes[coords] - shortCutTime};
//     bool foundShortCut = pathTimes.find(coords) != pathTimes.end() && 
//                         shortCutCoords.size() > 1 &&
//                         !checkIfBetterShortCut(shortCut, shortCuts) &&
//                         pathTimes[coords] > shortCutTime;

//     if(foundShortCut && shortCutCoords.size() >= 3 && !isWall(shortCutCoords[2])) {
//         // std::cout << "INSERT: [(" << shortCutCoords[1].first << "," << shortCutCoords[1].second << "),(" << shortCutCoords[2].first << "," << shortCutCoords[2].second << ")]: " << pathTimes[coords] - shortCutTime << std::endl;
//         // std::cin.get();
//         shortCuts.insert(shortCut);
//     }

//     // system("clear");
//     // printRaceWithShorcutAndVisited(shortCut, explored, shortCuts);

//     if (shortCutCoords.size() < 4) {
//         for(int rotation = 0; rotation < 4; rotation++) {
//             intPair nextCoords = moveCoord(coords, dir);
//             // std::cout << "EXPLORE (" << nextCoords.first << "," << nextCoords.second << ")" << std::endl;
//             // std::cin.get();
//             shortCutCoords.push_back(nextCoords);
//             exploreShortCut(shortCutCoords, shortCuts, explored);
//             shortCutCoords.pop_back();
//             // std::cout << "RETURN TO: " << shortCutCoords.size() << " | (" << coords.first << "," << coords.second << ")" << std::endl;
//             // std::cin.get();
//             rotateDirectionRight(dir, 1);
//         }
//     }

//     if(shortCutCoords.size() > 1) {
//         explored.erase(coords);
//     }
// }

bool Race::checkIfBetterShortCut(ShortCut ShortCutCandidate, const ShortCutSet& shortCuts) {
    for(ShortCut shortCuts : shortCuts) {
        if((shortCuts.firstCoord == ShortCutCandidate.firstCoord && 
            shortCuts.secondCoord == ShortCutCandidate.secondCoord &&
            shortCuts.timeDifference >= ShortCutCandidate.timeDifference)) {
            return true;
        }
    }
    return false;
}

bool Race::canMove(intPair coords, Direction dir) {
    intPair nextCoords = moveCoord(coords, dir);
    return !outOfBounds(nextCoords) && !isWall(nextCoords);
}

bool Race::canMove(intPair coords) {
    return !outOfBounds(coords) && !isWall(coords);
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

void Race::rotateDirectionRight(Direction& d, int times) {
    d = static_cast<Direction>((static_cast<int>(d) + times) % 4);
}

bool Race::outOfBounds(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(raceMap.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(raceMap[0].size()));
}

bool Race::isWall(intPair pos) {
    return raceMap[pos.first][pos.second] == '#';
}

void Race::printShortCutsByTime(const ShortCutSet& shortCuts) {
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

void Race::printRaceWithShorcutAndVisited(const ShortCut& shortCut, const std::set<intPair>& visited, const ShortCutSet& scs) {
    for(ShortCut s : scs) {
        std::cout << "[(" << s.firstCoord.first << "," << s.firstCoord.second << "),(" << s.secondCoord.first << "," << s.secondCoord.second << ")]: " << s.timeDifference << std::endl;
    }
    std::cout << std::endl << "  ";
    for(size_t i = 0; i < raceMap[0].size(); i++) {
        std::cout << i % 10 << " ";
    }
    std::cout << std::endl;
    for(size_t i = 0; i < raceMap.size(); i++) {
        std::cout << i % 10 << " ";
        for(size_t j = 0; j < raceMap[i].size(); j++) {
            if(shortCut.firstCoord.first == int(i) && shortCut.firstCoord.second == int(j)) {
                std::cout << "1 ";
            } else if(shortCut.secondCoord.first == int(i) && shortCut.secondCoord.second == int(j)) {
                std::cout << "2 ";
            } else if(visited.find({int(i),int(j)}) != visited.end()) {
                std::cout << "_ ";
            } else {
                std::cout << raceMap[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
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