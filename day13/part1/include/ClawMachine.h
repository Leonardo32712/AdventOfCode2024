#include <vector>
#include <iostream>
#include <string>
#include <cmath>

typedef std::pair<int,int> intPair;
typedef std::pair<float,float> floatPair;

class ClawMachine {
    private:
        const intPair buttonA;
        const intPair buttonB;
        const intPair prize;

        floatPair calculateButtonTimesPressed();
        bool areInteger(floatPair);
        bool tooMuchRepetitions(floatPair);
    public:
        ClawMachine(intPair, intPair, intPair);
        ~ClawMachine();

        int calculateMinimumTokenPrice();
        void printClawMachine();
};