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
        std::vector<Direction> moveProgram;
        size_t moveIteration;

    public:
        Robot(std::vector<Direction>);
        ~Robot();

        Direction move();
        void printRobotProgram();
};