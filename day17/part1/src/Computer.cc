#include "../include/Computer.h"

Computer::Computer(intVector r, intVector p) : registers(r), program(p) {}

Computer::~Computer() {}

void Computer::printPC() {
    printRegisters();
    std::cout << std::endl;
    printProgram();
}

void Computer::printRegisters() {
    for(size_t i = 0; i < registers.size(); i++) {
        std::cout << "Register " << static_cast<char>(i+65) << ": " << registers[i] << std::endl;
    }
}

void Computer::printProgram() {
    for(size_t i = 0; i < program.size(); i++) {
        std::cout << program[i];
        if(i < program.size() - 1) {
            std::cout << ", " << std::flush;
        }
    }
}