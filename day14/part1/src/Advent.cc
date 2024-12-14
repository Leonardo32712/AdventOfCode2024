#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    RobotSimulator Robots (fr.readRobots());

    Robots.printRobots();
    //std::cout << "BetterPrize: " << fewestPrice << std::endl << std::endl;

    return 0;
}

