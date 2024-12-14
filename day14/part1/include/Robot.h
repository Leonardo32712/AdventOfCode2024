#include <vector>
#include <iostream>


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
        void setPosition(int, int);
        void printRobot();
};