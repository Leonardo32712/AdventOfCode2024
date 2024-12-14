#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    std::vector<Robot> Robots (fr.readRobots());

    for( Robot r : Robots) {
        r.printRobot();
    }
    //std::cout << "BetterPrize: " << fewestPrice << std::endl << std::endl;

    return 0;
}

