#include <iostream>

#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {
    fileReader fr(argv[1]);
    StarShip ss (fr.readStarShipCodes());

    ss.printCodes();
    //std::cout << "" << std::endl;
    return 0;
}

