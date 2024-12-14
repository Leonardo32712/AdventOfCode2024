#include "../include/Robot.h"

Robot::Robot(intPair p, intPair v) : position(p), velocity(v) {}

Robot::~Robot() {}

void Robot::printRobot() {
    std::cout << "p=" << position.first << "," << position.second << " ";
    std::cout << "v=" << velocity.first << "," << velocity.second << std::endl;
}