#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    TopographicMap tm (fr.readTopographicMap());

    std::cout << "RatingSum: " << tm.getRatingSum() << std::endl;
    return 0;
}

