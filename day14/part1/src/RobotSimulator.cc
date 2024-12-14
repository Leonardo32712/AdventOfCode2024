#include "../include/RobotSimulator.h"

RobotSimulator::RobotSimulator(std::vector<Robot> r) : robots(r) {}

RobotSimulator::~RobotSimulator() {}

bool RobotSimulator::outOfBounds(size_t i, size_t j) {
    return (i < 0 || i >= TALL || j < 0 || j >= WIDE);
}

void RobotSimulator::printRobots() {
    for(Robot r : robots) {
        r.printRobot();
    }
}