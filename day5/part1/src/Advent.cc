#include <iostream>
#include <string>
#include <vector>

#include "fileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    safetyManual sm = fr.readManual();
    sm.printManual();

    return 0;
}