#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    CityMap cm (fr.readCityMap());
    cm.printCityData();

    return 0;
}

