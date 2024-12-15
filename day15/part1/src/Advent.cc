#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    RobotSimulator Robots (fr.readRobots());

    std::cout << Robots.getSafetyFactor(100) << std::endl;

    return 0;
}

