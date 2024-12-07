#include "fileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    safetyManual sm = fr.readManual();

    std::cout << "The summary of correct middle pages is " << sm.sumCorrectPages() << std::endl;

    return 0;
}

