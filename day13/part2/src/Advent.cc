#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    std::vector<ClawMachine> clawMachines (fr.readClawMachines());

    long int fewestPrice = 0;
    for( ClawMachine cm : clawMachines) {
        fewestPrice += cm.calculateMinimumTokenPrice();
    }
    std::cout << "BetterPrize: " << fewestPrice << std::endl << std::endl;

    return 0;
}

