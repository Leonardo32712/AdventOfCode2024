#include "../include/ClawMachine.h"

ClawMachine::ClawMachine(intPair a, intPair b, intPair p) : buttonA(a), buttonB(b), prize(p) {}

ClawMachine::~ClawMachine() {}

int ClawMachine::calculateMinimumTokenPrice() {
    floatPair timesPressed(calculateButtonTimesPressed());
    if(!areInteger(timesPressed) || tooMuchRepetitions(timesPressed)) {
        return 0;
    } else {
        return (3*timesPressed.first + timesPressed.second);
    }
}

floatPair ClawMachine::calculateButtonTimesPressed() {
    floatPair a = buttonA;
    floatPair b = buttonB;
    floatPair c = prize;

    float timesA = ((c.first*b.second) - (c.second*b.first))/((a.first*b.second) - (a.second*b.first));
    float timesB = ((a.first*c.second) - (a.second*c.first))/((a.first*b.second) - (a.second*b.first));
    return floatPair(timesA, timesB);
}

bool ClawMachine::areInteger(floatPair f) {
    return (floorf(f.first) == f.first && floorf(f.second) == f.second);
}

bool ClawMachine::tooMuchRepetitions(floatPair f) {
    return (f.first > 100 || f.second > 100);
}

void ClawMachine::printClawMachine() {
    std::cout << "Button A: X+" << buttonA.first << ", Y+" << buttonA.second << std::endl;
    std::cout << "Button B: X+" << buttonB.first << ", Y+" << buttonB.second << std::endl;
    std::cout << "Prize: X=" << prize.first << ", Y=" << prize.second << std::endl;
}