#include "../include/Maze.h"

Maze::Maze(std::vector<std::string> map) : mazeMap(map) {
    reindeerDirection = RIGHT;
    findStartAndEnd(); 
}

Maze::~Maze() {}

void Maze::findStartAndEnd() {
    for(size_t i = 0; i < mazeMap.size(); i++) {
        for(size_t j = 0; j < mazeMap[i].size(); j++) {
            if(mazeMap[i][j] == 'S') { start = intPair(i,j); }
            if(mazeMap[i][j] == 'E') { end = intPair(i,j); }
        }
    }
}

long Maze::getLowestScore() {
    return explorePath(start, reindeerDirection);
}

long Maze::explorePath(const intPair originalCoords, const Direction originaldirection) {
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    std::set<std::tuple<intPair, Direction>> visited;
    long bestScore = __LONG_MAX__;

    Direction dir = originaldirection;
    for (int i = 0; i < 4; i++) {
        pq.push({dir, originalCoords, std::min(i*1000,(4-i)*1000)});
        dir = rotateDirectionRight(dir);
    }

    while(!pq.empty()) {
        State current = pq.top();
        pq.pop();

        intPair coords = current.coords;
        dir = current.dir;
        int score = current.score;

        if(visited.find({coords, dir}) == visited.end()) {
            visited.insert({coords, dir});
            if(coords == end && score < bestScore) {
                bestScore = score;
            }

            intPair next = moveCoord(coords, dir);
            if(!outOfBounds(next) && !isWall(next)) {
                pq.push({dir, next, score + 1});
            }

            dir = rotateDirectionRight(current.dir);
            next = moveCoord(coords, dir);
            if(!outOfBounds(next) && !isWall(next)) {
                pq.push({dir, next, score + 1001});
            }

            dir = rotateDirectionLeft(current.dir);
            next = moveCoord(coords, dir);
            if(!outOfBounds(next) && !isWall(next)) {
                pq.push({dir, next, score + 1001});
            }
        }
    }

    return bestScore;
}

void Maze::recordDirection(intPair coords, Direction d) {
    switch (d) {
        case UP:    mazeMap[coords.first][coords.second] = '^'; break;
        case RIGHT: mazeMap[coords.first][coords.second] = '>'; break;
        case DOWN:  mazeMap[coords.first][coords.second] = 'v'; break;
        case LEFT:  mazeMap[coords.first][coords.second] = '<'; break;
    }
}

intPair Maze::moveCoord(intPair coords, Direction d) {
    switch (d) {
        case UP: return intPair(coords.first - 1, coords.second);
        case RIGHT: return intPair(coords.first, coords.second + 1);
        case DOWN: return intPair(coords.first + 1, coords.second);
        case LEFT: return intPair(coords.first, coords.second - 1);
    }
    return coords;
}

Direction Maze::rotateDirectionRight(Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 1) % 4);
}

Direction Maze::rotateDirectionLeft(Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 3) % 4);
}

bool Maze::outOfBounds(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(mazeMap.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(mazeMap[0].size()));
}

bool Maze::isWall(intPair pos) {
    return mazeMap[pos.first][pos.second] == '#';
}

bool Maze::isVisited(intPair pos) {
    return  mazeMap[pos.first][pos.second] == '_' || 
            mazeMap[pos.first][pos.second] == '^' ||
            mazeMap[pos.first][pos.second] == '>' ||
            mazeMap[pos.first][pos.second] == '<' ||
            mazeMap[pos.first][pos.second] == 'v';
}

void Maze::printMaze() {
    for(std::string line : mazeMap) {
        for(char c : line) {
            std::cout << c;
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
}