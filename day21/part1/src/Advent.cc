#include <iostream>

#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {
    fileReader fr(argv[1]);
    StarShip ss (fr.readStarShipCodes());

    std::cout << ss.getComplexitySum() << std::endl;
    return 0;
}

