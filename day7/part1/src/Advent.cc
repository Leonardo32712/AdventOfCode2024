#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {
    FileReader fr(argv[1]);
    equationVector equations = fr.readEquations();

    long long totalCalibration = 0;
    for(size_t i = 0; i < equations.size(); i++) {
        if(equations[i].canBeSolved()) {
            totalCalibration += equations[i].getIndependentTerm();
        }
    }

    std::cout << "Total calibration result: " << totalCalibration << std::endl;
    return 0;
}

