#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <optional>


typedef std::pair<int,int> intPair;

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

struct State {
    Direction dir;
    intPair coords;
    long score;

    bool operator!=(const State &other) const {
        return score != other.score ||
                coords != other.coords ||
                score != other.score;
    }
    
    bool operator>(const State &other) const {
        return score > other.score;
    }

    bool operator<(const State& other) const {
        if (coords != other.coords) {
            return coords < other.coords; // Ordena por coordenadas
        } else if(dir != other.dir) {
            return dir < other.dir; // Luego ordena por dirección
        } else {
            return score < other.score;
        }
    }
};

class Maze {
    private:
        std::vector<std::string> mazeMap;
        Direction reindeerDirection;
        intPair start;
        intPair end;

        void findStartAndEnd();
        State processNextState(std::map<State, std::set<State>>&, const State&, const State&, const long);
        bool outOfBounds(intPair);
        bool isWall(intPair);
        bool isVisited(intPair);
        intPair moveCoord(intPair, Direction);
        Direction rotateDirectionRight(Direction, int);
        long backtrackCount(const std::map<State, std::set<State>>&, State);
        std::string directionToString(Direction);
    public:
        Maze(std::vector<std::string>);
        ~Maze();

        long getBestPathsTilesCount();
        void printMaze();
};