#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Computer pc (fr.readPC());

    pc.printPC();
    pc.getProgramResult();
    std::cout << std::endl << "Program result: ";
    pc.printOutput();

    return 0;
}

