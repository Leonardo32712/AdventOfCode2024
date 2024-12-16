#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

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
    int score;
    
    bool operator>(const State &other) const {
        return score > other.score;
    }
};

class Maze {
    private:
        std::vector<std::string> mazeMap;
        Direction reindeerDirection;
        intPair start;
        intPair end;

        void findStartAndEnd();
        long explorePath(const intPair, const Direction);
        bool outOfBounds(intPair);
        bool isWall(intPair);
        bool isVisited(intPair);
        intPair moveCoord(intPair, Direction);
        Direction rotateDirectionRight(Direction);
        Direction rotateDirectionLeft(Direction);
        void recordDirection(intPair, Direction);
    public:
        Maze(std::vector<std::string>);
        ~Maze();

        long getLowestScore();
        void printMaze();
};