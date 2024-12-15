#include <vector>
#include <iostream>

typedef std::pair<int,int> intPair;

enum Direction {
    NONE = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

class Robot {
    private:
        intPair position;
        std::vector<Direction> moveProgram;
        size_t moveIteration;

    public:
        Robot(std::vector<Direction>, intPair);
        ~Robot();

        Direction nextMove();
        void setPosition(intPair);
        intPair getPosition();
        void resetProgram();
        void printRobotProgram();
};