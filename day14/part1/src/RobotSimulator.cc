#include "../include/RobotSimulator.h"

RobotSimulator::RobotSimulator(std::vector<Robot> r) : robots(r) {}

RobotSimulator::~RobotSimulator() {}

long RobotSimulator::getSafetyFactor(int seconds) {
    for(int i = 0; i < seconds; i++) {
        for(Robot &r : robots) {
            r.move();
        }
    }

    return calculateSafetyFactor(getQuadrants());
}

long RobotSimulator::calculateSafetyFactor(std::vector<int> quadrants) {
    long safetyFactor = 1;
    for(int q : quadrants) {
        if(q != 0) {
            safetyFactor *= q;
        }
    }
    return safetyFactor;
}

std::vector<int> RobotSimulator::getQuadrants() {
    std::vector<int> quadrants = {0,0,0,0};
    for(Robot &r : robots) {
        switch (r.getQuadrant()) {
            case 1:
                quadrants[0]++;
                break;
            case 2:
                quadrants[1]++;
                break;
            case 3:
                quadrants[2]++;
                break;
            case 4:
                quadrants[3]++;
                break;
            default:
                break;
        }
    }
    return quadrants;
}

void RobotSimulator::printRobots() {
    for(Robot r : robots) {
        r.printRobot();
    }
}