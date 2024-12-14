#include <vector>
#include <iostream>
#include <string>
#include <cmath>

typedef std::pair<int,int> intPair;
typedef std::pair<float,float> floatPair;

class Robot {
    private:
        const intPair position;
        const intPair velocity;

        floatPair calculateButtonTimesPressed();
    public:
        Robot(intPair, intPair);
        ~Robot();

        int calculateMinimumTokenPrice();
        void printRobot();
};