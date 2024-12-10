#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    TopographicMap dm (fr.readTopographicMap());

    std::cout << "Checksum: " << std::endl;
    return 0;
}

