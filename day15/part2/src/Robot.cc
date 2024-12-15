#include "../include/Robot.h"

Robot::Robot(std::vector<Direction> program, intPair pos) : moveProgram(program) {
    position = pos;
    moveIteration = 0;
}

Robot::~Robot() {}

Direction Robot::nextMove() {
    if(moveIteration < moveProgram.size()) {
        Direction d = moveProgram[moveIteration];
        moveIteration++;
        return d;
    } else {
        return NONE;
    }
}

void Robot::setPosition(intPair pos) {
    position = pos;
}

intPair Robot::getPosition() {
    return position;
}

void Robot::resetProgram() {
    moveIteration = 0;
}

void Robot::printRobotProgram() {
    for( Direction d : moveProgram) {
        switch (d) {
            case 1:
                std::cout << '^' << std::flush;
                break;
            case 2:
                std::cout << '>' << std::flush;
                break;
            case 3:
                std::cout << 'v' << std::flush;
                break;
            case 4:
                std::cout << '<' << std::flush;
                break;
            default:
                break;
        }
    }
}
