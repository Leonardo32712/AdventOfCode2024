#include "../include/Computer.h"

Computer::Computer(intPairVector m) : corruptedMemory(m) {}

Computer::~Computer() {}

intPair Computer::getFirstBlock() {
    int bytesTop = corruptedMemory.size() - 1;
    int bytesBot = 0;
    int simulationResult;
    int bytesMid = bytesBot + (bytesTop - bytesBot) / 2;
    while(bytesBot < bytesTop) {
        bytesMid = bytesBot + (bytesTop - bytesBot) / 2;
        simulationResult = simulate(bytesMid);
        if(simulationResult == -1) {
            bytesTop = bytesMid;
        } else {
            bytesBot = bytesMid + 1;
        }
    }
    if(bytesTop < static_cast<int>(corruptedMemory.size())) {
        return corruptedMemory[bytesMid];
    } else {
        return intPair(-1,-1);
    }
}

long Computer::simulate(int bytes) {
    intPairVector corruptedBytes(corruptedMemory.begin(), corruptedMemory.begin() + bytes);
    long bestPathCount = getBestPath(corruptedBytes);
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