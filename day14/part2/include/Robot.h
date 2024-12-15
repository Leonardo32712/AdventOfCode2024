#include <vector>
#include <iostream>

const int WIDE = 101;
const int TALL = 103;

typedef std::pair<int,int> intPair;

class Robot {
    private:
        const intPair velocity;
        intPair position;
        

    public:
        Robot(intPair, intPair);
        ~Robot();

        intPair getVelocity();
        intPair getPosition();
        void move();
        int getQuadrant();
        void printRobot();
};