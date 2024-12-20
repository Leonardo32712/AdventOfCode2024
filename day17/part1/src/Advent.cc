#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Computer pc (fr.readPC());

    pc.printPC();
    //std::cout <<  << std::endl;

    return 0;
}

