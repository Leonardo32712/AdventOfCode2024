#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    RobotSimulator Robots (fr.readRobots());

    std::cout << std::endl;

    return 0;
}

