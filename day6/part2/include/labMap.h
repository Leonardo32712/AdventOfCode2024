#include <vector>
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdlib>

typedef std::pair<int,int> intPair;
typedef std::vector<std::string> stringVector;

enum Direction {
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

class labMap {
    private:
        stringVector map;
        intPair guardStartingPosition;
        Direction guardDirection;
        bool loopfound;
        bool guardLeavingMap;

        intPair searchGuardPosition();
        Direction searchGuardDirection(const intPair);

        void moveGuard(intPair&);
        void adjustGuardRotation(const intPair);
        bool checkNextMove(const intPair);
        intPair getNextPosition(const intPair&) const;
        bool isOutOfBounds(const intPair&) const;
        bool evaluateCell(char);
        char getDirectionChar();
    public:
        labMap(stringVector);
        ~labMap();

        void resetMap(const stringVector);
        stringVector getMap();
        bool startSimulation(int, int);
        void printLab(const intPair);
};
