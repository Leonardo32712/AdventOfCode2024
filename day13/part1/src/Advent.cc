#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    std::vector<ClawMachine> clawMachines (fr.readClawMachines());

    for( ClawMachine cm : clawMachines) {
        cm.printClawMachine();
        std::cout << std::endl;
    }

    //std::cout << "Total price: " << g.totalPrice() << std::endl;
    return 0;
}

