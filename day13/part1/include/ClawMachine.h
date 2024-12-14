#include <vector>
#include <iostream>
#include <string>

typedef std::pair<int,int> intPair;

class ClawMachine {
    private:
        const intPair buttonA;
        const intPair buttonB;
        const intPair prize;

    public:
        ClawMachine(intPair, intPair, intPair);
        ~ClawMachine();

        void printClawMachine();
};