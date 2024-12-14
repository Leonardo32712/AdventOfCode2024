#include <vector>
#include <iostream>
#include <string>
#include <cmath>

const long double ERROR = 10000000000000;

typedef std::pair<long double, long double> doublePair;

class ClawMachine {
    private:
        const doublePair buttonA;
        const doublePair buttonB;
        const doublePair prize;

        doublePair calculateButtonTimesPressed();
        bool areInteger(doublePair);
    public:
        ClawMachine(doublePair, doublePair, doublePair);
        ~ClawMachine();

        long long calculateMinimumTokenPrice();
        void printClawMachine();
};