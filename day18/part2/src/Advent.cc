#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Computer pc (fr.readPC());

    intPair result = pc.getFirstBlock();
    std::cout << "First block byte: " << result.first << "," << result.second << std::endl;

    return 0;
}

