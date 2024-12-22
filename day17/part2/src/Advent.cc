#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Computer pc (fr.readPC());

    std::cout << std::endl << "Register A initial value: " << pc.findInitialRegisterA();

    return 0;
}