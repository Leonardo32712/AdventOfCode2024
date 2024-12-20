#include "../include/Computer.h"

Computer::Computer(longVector r, longVector p) : registers(r), program(p) {
    IP = 0;
    jumped = false;
}

Computer::~Computer() {}

longVector Computer::getProgramResult() {
    while (IP < static_cast<int>(program.size())) {
        operate(program[IP], program[IP + 1]);
        if(!jumped) {
            IP += 2;
        } else {
            jumped = false;
        }
    }

    return output;
}

void Computer::operate(int opcode, long operand) {
    switch (opcode) {
        case ADV: registers[0] = registers[0] / (pow(2, getComboOP(operand))); break;
        case BXL: registers[1] = registers[1] ^ operand; break;
        case BST: registers[1] = getComboOP(operand) % 8; break;
        case JNZ:
            if(registers[0] != 0) {
                IP = operand;
                jumped = true;
            } break;
        case BXC: registers[1] = registers[1] ^ registers[2]; break;
        case OUT: output.push_back(getComboOP(operand) % 8); break;
        case BDV: registers[1] = registers[0] / (pow(2, getComboOP(operand))); break;
        case CDV: registers[2] = registers[0] / (pow(2, getComboOP(operand))); break;
        default: break;
    }
}

long Computer::getComboOP(long operand) {
    switch (operand) {
        case 0: case 1: case 2: case 3: return operand;
        case 4: case 5: case 6: return registers[operand - 4];
        default: return operand;
    }
}

void Computer::printPC() {
    printRegisters();
    std::cout << std::endl;
    printProgram();
    std::cout << std::endl;
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

void Computer::printOutput() {
    for(size_t i = 0; i < output.size(); i++) {
        std::cout << output[i];
        if(i < output.size() - 1) {
            std::cout << "," << std::flush;
        }
    }
}