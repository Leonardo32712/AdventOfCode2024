#include "../include/Warehouse.h"

Warehouse::Warehouse(std::vector<std::string> map, std::vector<Direction> r) : robot(r) {
    wareHouseMap = map;
}

Warehouse::~Warehouse() {}

long Warehouse::getSumGPS() {
    return 0;
}

void Warehouse::printWarehouse() {
    for(std::string line : wareHouseMap) {
        for(char c : line) {
            std::cout << c << " " << std::flush;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    robot.printRobotProgram();
}