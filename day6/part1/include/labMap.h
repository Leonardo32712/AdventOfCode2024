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
        Direction direction;
        int pathCounter;
        bool guardExited;

        void searchGuard();
        void moveGuard(intPair&);
        void countSteps(const intPair);
        bool checkMove(const intPair);
    public:
        labMap(stringVector);
        ~labMap();

        void startSimulation();
        int getPathCounter();
        void printLab(const intPair);
};
