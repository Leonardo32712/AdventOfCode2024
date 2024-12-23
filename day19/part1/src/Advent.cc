#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Onsen o (fr.readOnsen());

    std::cout << "Possible desings: " << o.possibleDesigns();

    return 0;
}

