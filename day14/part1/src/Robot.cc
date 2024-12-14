#include "../include/Robot.h"

Robot::Robot(intPair p, intPair v) : position(p), velocity(v) {}

Robot::~Robot() {}

intPair Robot::getVelocity() {
    return velocity;
}

intPair Robot::getPosition() {
    return position;
}

void Robot::setPosition(int x, int y) {
    position = intPair(x,y);
}

void Robot::printRobot() {
    std::cout << "p=" << position.first << "," << position.second << " ";
    std::cout << "v=" << velocity.first << "," << velocity.second << std::endl;
}
