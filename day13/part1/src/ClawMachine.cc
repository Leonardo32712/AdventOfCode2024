#include "../include/ClawMachine.h"

ClawMachine::ClawMachine(intPair a, intPair b, intPair p) : buttonA(a), buttonB(b), prize(p) {}

ClawMachine::~ClawMachine() {}

void ClawMachine::printClawMachine() {
    std::cout << "Button A: X+" << buttonA.first << ", Y+" << buttonA.second << std::endl;
    std::cout << "Button B: X+" << buttonB.first << ", Y+" << buttonB.second << std::endl;
    std::cout << "Prize: X=" << prize.first << ", Y=" << prize.second << std::endl;
}