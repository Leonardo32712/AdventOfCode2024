#include <iostream>

#include "../include/StarShip.h"

StarShip::StarShip(std::vector<std::string> c) {
    codes = c;
    keyPads = {KeyPad(true), KeyPad(false), KeyPad(false)};
}

StarShip::~StarShip() {}

std::string StarShip::getInstructions(char button, size_t keyPadIndex) {
    if(keyPadIndex >= keyPads.size()) {
        return std::string(1, button);
    }

    std::string instructions = keyPads[keyPadIndex].moveTo(button);
    std::string result = "";

    // std::cout << "KPI: " << keyPadIndex << std::endl;
    // std::cout << "Button: " << button << std::endl;
    // std::cout << "Ins: " << instructions << std::endl;
    for(char instruction: instructions) {
        result += getInstructions(instruction, keyPadIndex + 1);
    }
    
        // std::cout << "Result: " << result << std::endl << std::endl;

    return result;
}

long StarShip::getComplexitySum() {
    std::string instructions;
    long sum = 0;

    for(std::string code: codes) {
        //std::cout << code << ": ";
        for(char button: code) {
            instructions += getInstructions(button, 0);
        }
        sum += codeToInt(code)*instructions.size();
        //std::cout << instructions << std::endl;
        instructions.clear();
    }

    return sum;
}

int StarShip::codeToInt(std::string code) {
    std::string result;

    for (char ch : code) {
        if (ch != 'A') {
            result += ch;
        }
    }

    return std::stoi(result);
}

void StarShip::printCodes() {
    for(std::string c: codes) {
        // std::cout << c << std::endl;
    }
}