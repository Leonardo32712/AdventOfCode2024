#include <iostream>

#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {
    fileReader fr(argv[1]);
    Race race (fr.readRace());

    std::cout << race.getShortCutsCountByMinTimeSaved(100) << std::endl;
    return 0;
}

