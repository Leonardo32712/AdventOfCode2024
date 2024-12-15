#include "../include/Robot.h"

Robot::Robot(intPair p, intPair v) : velocity(v), position(p)  {}

Robot::~Robot() {}

intPair Robot::getVelocity() {
    return velocity;
}

intPair Robot::getPosition() {
    return position;
}

int Robot::getQuadrant() {
    if(position.first < WIDE/2 && position.second < TALL/2) {
        return 1;
    }

    if(position.first < WIDE/2 && position.second > TALL/2) {
        return 2;
    }

    if(position.first > WIDE/2 && position.second < TALL/2) {
        return 3;
    }

    if(position.first > WIDE/2 && position.second > TALL/2) {
        return 4;
    }

    return 0;
}

void Robot::move() {
    int x = position.first + velocity.first;
    int y = position.second + velocity.second;

    if(x < 0) { x += WIDE; }
    if(x >= WIDE) { x -= WIDE; }
    if(y < 0) { y += TALL; }
    if(y >= TALL) { y -= TALL; }

    position = intPair(x,y);
}

void Robot::printRobot() {
    std::cout << "p=" << position.first << "," << position.second << " ";
    std::cout << "v=" << velocity.first << "," << velocity.second << std::endl;
}
