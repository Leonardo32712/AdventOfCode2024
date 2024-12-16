#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Warehouse wh (fr.readRobots());

    wh.printWarehouse();
    wh.doubleWide();
    wh.printWarehouse();
    wh.simulateMove();
    wh.printWarehouse();
    std::cout << "Summary GPS: " << wh.getSumGPS() << std::endl;
    return 0;
}