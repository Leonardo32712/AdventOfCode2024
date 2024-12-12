#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Garden g (fr.readgardenMap());

    g.printGarden();
    //std::cout << "ScoreSum: " << tm.getScoreSum() << std::endl;
    return 0;
}

