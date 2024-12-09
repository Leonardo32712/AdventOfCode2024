#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    CityMap cm (fr.readCityMap());
    int totalAntinodes = cm.markAndCountAntinodes();
    //cm.printCity();
    //cm.printCityData();
    std::cout << "There are " << totalAntinodes << " antinodes." << std::endl;
    return 0;
}

