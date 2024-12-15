#include "../include/Robot.h"

Robot::Robot(std::vector<Direction> program) : moveProgram(program), moveIteration(0) {}

Robot::~Robot() {}

Direction Robot::move() {
    if(moveIteration < moveProgram.size()) {
        Direction d = moveProgram[moveIteration];
        moveIteration++;
        return d;
    } else {
        return NONE;
    }
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
