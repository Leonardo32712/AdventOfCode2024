#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Computer pc (fr.readPC());

    std::cout << "Minimum number of steps: " << pc.simulate(1024);

    return 0;
}

