#include "../include/RobotSimulator.h"

RobotSimulator::RobotSimulator(std::vector<Robot> r) : originalRobots(r), robots(r) {}

RobotSimulator::~RobotSimulator() {}

long RobotSimulator::getBestConnection(int seconds) {
    int bestSecond = 0;
    long bestConnection = getConections();

    for(int s = 1; s <= seconds; s++) {
        for(Robot &r : robots) {
            r.move();
        }

        long newConnection = getConections();
        if(newConnection < bestConnection) {
            bestSecond = s;
            bestConnection = newConnection;
        }
    }

    resetRobots();
    return bestSecond;
}

long RobotSimulator::getConections() {
    long connectionCounterX = 0;
    long connectionCounterY = 0;
    for(size_t i = 0; i < robots.size() - 1; i++) {
        for(size_t j = i + 1; j < robots.size(); j++) {
            intPair rFirst = robots[i].getPosition();
            intPair rSecond = robots[j].getPosition();
            connectionCounterX += abs(rFirst.first - rSecond.first);
            connectionCounterY += abs(rFirst.second - rSecond.second);
        }
    }

    return connectionCounterX + connectionCounterY;
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

void RobotSimulator::resetRobots() {
    robots.clear();
    for(Robot r : originalRobots) {
        robots.push_back(r);
    }
}

void RobotSimulator::printRobots(int seconds = 0) {
    for(int s = 1; s <= seconds; s++) {
        for(Robot &r : robots) {
            r.move();
        }
    }

    for(int j = 0; j < TALL; j++) {
        for(int i = 0; i < WIDE; i++) {
            char output = '.';
            for(Robot &r : robots) {
                if(r.getPosition().first == i && r.getPosition().second == j) {
                    output = '#';
                }
            }
            std::cout << output << " " << std::flush;
        }
        std::cout << std::endl;
    }
    std::cout << "Second: " << seconds << std::endl;
    resetRobots();
}