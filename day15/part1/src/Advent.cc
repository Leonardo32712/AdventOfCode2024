#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Warehouse wh (fr.readRobots());

    std::cout << wh.getSumGPS() << std::endl;

    return 0;
}

