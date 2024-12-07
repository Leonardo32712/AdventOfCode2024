#include "../include/fileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    labMap map = fr.readLabMap();
    map.startSimulation();

    std::cout << "The guard will visit " << map.getPathCounter() << " distinct positions" << std::endl;

    return 0;
}

