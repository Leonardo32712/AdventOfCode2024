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

long Maze::getBestPathsTilesCount() {
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
    std::map<State, std::set<State>> cameFrom;
    std::map<intPair, long> visited;
    State lastState;

    Direction dir = RIGHT;
    for (int i = 0; i < 4; i++) {
        pq.push({dir, start, std::min(i*1000,(4-i)*1000)});
        dir = rotateDirectionRight(dir,1);
    }

    while(!pq.empty()) {
        State current = pq.top();
        pq.pop();

        const intPair coords = current.coords;
        const Direction dir = current.dir;
        const long score = current.score;

        if(visited.find(coords) == visited.end() || (visited[coords] > score)) {            
            visited[coords] = score;
            if(coords == end) {
                lastState = {dir,coords,score};
            }

            State nextState = processNextState(cameFrom, current, {dir, moveCoord(coords, dir), score}, 1);
            if(nextState != current) {
                pq.push(nextState);
            }

            Direction nextDir = rotateDirectionRight(dir,1);
            nextState = processNextState(cameFrom, current, {nextDir, moveCoord(coords, nextDir), score}, 1001);
            if(nextState != current) {
                pq.push(nextState);
            }

            nextDir = rotateDirectionRight(dir, 3);
            nextState = processNextState(cameFrom, current, {nextDir, moveCoord(coords, nextDir), score}, 1001);
            if(nextState != current) {
                pq.push(nextState);
            }
        }
    }

    return backtrackCount(cameFrom, lastState);
}

State Maze::processNextState(std::map<State, std::set<State>>& cameFrom, const State& original, const State& next, const long score) {
    if(!outOfBounds(next.coords) && !isWall(next.coords)) {
        if(score == 1) {
            cameFrom[{next.dir, next.coords, original.score + score}].insert(original);
        } else {
            cameFrom[{next.dir, next.coords, original.score + score}].insert({next.dir, original.coords, original.score + 1000});
            cameFrom[{next.dir, original.coords, original.score + 1000}].insert(original);
        }
        return State{next.dir, next.coords, original.score + score};
    } else {
        return original;
    }
}

long Maze::backtrackCount(const std::map<State, std::set<State>>& cameFrom, State current) {
    intPair coords = current.coords;
    long count = 0;

    if(cameFrom.find(current) != cameFrom.end() && coords != start) {
        std::set<State> preStates = cameFrom.at(current);

        for(State s : preStates) {
            count += backtrackCount(cameFrom, s);
        }
    }

    if(mazeMap[coords.first][coords.second] != 'O') {
        mazeMap[coords.first][coords.second] = 'O';
        return count + 1;
    } else {
        return count;
    }
}

intPair Maze::moveCoord(intPair coords, Direction d) {
    switch (d) {
        case UP: return intPair(coords.first - 1, coords.second);
        case RIGHT: return intPair(coords.first, coords.second + 1);
        case DOWN: return intPair(coords.first + 1, coords.second);
        case LEFT: return intPair(coords.first, coords.second - 1);
        default: return coords;
    }
}

Direction Maze::rotateDirectionRight(Direction d, int times) {
    return static_cast<Direction>((static_cast<int>(d) + times) % 4);
}

bool Maze::outOfBounds(intPair pos) {
    return (pos.first < 0 || pos.first >= static_cast<int>(mazeMap.size()) || 
            pos.second < 0 || pos.second >= static_cast<int>(mazeMap[0].size()));
}

bool Maze::isWall(intPair pos) {
    return mazeMap[pos.first][pos.second] == '#';
}

bool Maze::isVisited(intPair pos) {
    return  mazeMap[pos.first][pos.second] == '^' ||
            mazeMap[pos.first][pos.second] == '>' ||
            mazeMap[pos.first][pos.second] == '<' ||
            mazeMap[pos.first][pos.second] == 'v';
}

std::string Maze::directionToString(Direction dir) {
    switch (dir) {
        case UP: return "UP";
        case LEFT: return "LEFT";
        case DOWN: return "DOWN";
        case RIGHT: return "RIGHT";
        default: return "?";
    }
}

void Maze::printMaze() {
    for(size_t i = 0; i < mazeMap[0].size(); i++) {
        std::cout << i%10 << " ";
    }
    std::cout << "\n";
    for(size_t i = 0; i < mazeMap.size(); i++) {
        for(char c : mazeMap[i]) {
            std::cout << c << " ";
        }
        std::cout << i%10 << "\n";
    }

    std::cout << std::endl;
}
