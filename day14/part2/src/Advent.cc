#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    RobotSimulator robots (fr.readRobots());

    robots.printRobots(robots.getBestConnection(8000));

    return 0;
}

