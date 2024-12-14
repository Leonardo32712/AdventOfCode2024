#include "../include/ClawMachine.h"

ClawMachine::ClawMachine(doublePair a, doublePair b, doublePair p) : 
    buttonA(a), 
    buttonB(b), 
    prize(doublePair(p.first + ERROR, p.second + ERROR)) {}

ClawMachine::~ClawMachine() {}

long long int ClawMachine::calculateMinimumTokenPrice() {
    doublePair timesPressed(calculateButtonTimesPressed());
    if(!areInteger(timesPressed)) {
        return 0;
    } else {
        return (3*timesPressed.first + timesPressed.second);
    }
}

doublePair ClawMachine::calculateButtonTimesPressed() {
    const doublePair a = buttonA;
    const doublePair b = buttonB;
    const doublePair c = prize;

    long double timesA = ((c.first*b.second) - (c.second*b.first))/((a.first*b.second) - (a.second*b.first));
    long double timesB = ((a.first*c.second) - (a.second*c.first))/((a.first*b.second) - (a.second*b.first));
    return doublePair(timesA, timesB);
}

bool ClawMachine::areInteger(doublePair f) {
    return (std::fabs(f.first - floorl(f.first)) < 1e-9 && std::fabs(f.second - floorl(f.second)) < 1e-9);
}

void ClawMachine::printClawMachine() {
    std::cout << "Button A: X+" << buttonA.first << ", Y+" << buttonA.second << std::endl;
    std::cout << "Button B: X+" << buttonB.first << ", Y+" << buttonB.second << std::endl;
    std::cout << "Prize: X=" << prize.first << ", Y=" << prize.second << std::endl;
}