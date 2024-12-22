#include "../include/Computer.h"

Computer::Computer(intPairVector m) : 
        corruptedMemory(m), 
        memorySpace(MAX_MEMORY_SPACE + 1, std::string(MAX_MEMORY_SPACE + 1, '.')) {}

Computer::~Computer() {}

long Computer::simulate(int bytes) {
    for(int i = 0; i < 1024; i++) {
        memorySpace[corruptedMemory[i].first][corruptedMemory[i].second] = '#';
    }
    intPairVector corruptedBytes(corruptedMemory.begin(), corruptedMemory.begin() + bytes);
    long bestPathCount = getBestPath(corruptedBytes);
    clearBytes();
    return bestPathCount;
}

long Computer::getBestPath(intPairVector corruptedBytes) {
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    std::map<intPair, long> visited;
    long bestPathCost = __LONG_MAX__;

    pq.push({{0,0}, 0});

    while(!pq.empty()) {
        State current = pq.top();
        pq.pop();

        const intPair coords = current.coords;
        const long cost = current.cost;

        if(visited.find(coords) == visited.end() || (visited[coords] > cost)) {
            if(coords == END_COORDS && cost < bestPathCost) {
                bestPathCost = cost;
            }

            visited[coords] = cost;
            
            Direction dir = RIGHT;
            for (int i = 0; i < 4; i++) {
                intPair nextCoords = moveCoord(coords, dir);
                if(!outOfBounds(nextCoords) && !isCorrupted(nextCoords, corruptedBytes)) {
                    pq.push({nextCoords, cost + 1});
                }
                dir = rotateDirectionRight(dir,1);
            }
        }
    }

    return bestPathCost != __LONG_MAX__ ? bestPathCost : -1;
}

intPair Computer::moveCoord(intPair coords, Direction d) {
    switch (d) {
        case UP: return intPair(coords.first - 1, coords.second);
        case RIGHT: return intPair(coords.first, coords.second + 1);
        case DOWN: return intPair(coords.first + 1, coords.second);
        case LEFT: return intPair(coords.first, coords.second - 1);
        default: return coords;
    }
}

Direction Computer::rotateDirectionRight(Direction d, int times) {
    return static_cast<Direction>((static_cast<int>(d) + times) % 4);
}

bool Computer::outOfBounds(intPair byte) {
    return (byte.first < 0 || byte.first > MAX_MEMORY_SPACE || 
            byte.second < 0 || byte.second > MAX_MEMORY_SPACE);
}

bool Computer::isCorrupted(intPair byte, intPairVector corruptedBytes) {
    for(intPair cb : corruptedBytes) {
        if(byte == cb) {
            return true;
        }
    }

    return false;
}

void Computer::clearBytes() {
    for(int i = 0; i <= MAX_MEMORY_SPACE; i++) {
        for(int j = 0; j <= MAX_MEMORY_SPACE; j++) {
            if(memorySpace[i][j] == '#') {
                memorySpace[i][j] = '.';
            }
        }
    }
}

void Computer::printCorrupted() {
    for(intPair cb : corruptedMemory) {
        std::cout << cb.first << "," << cb.second << std::endl;
    }
}

void Computer::printMemorySpace() {
    for(std::string ms : memorySpace) {
        std::cout << ms << std::endl;
    }
}