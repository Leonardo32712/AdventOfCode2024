#include "../include/Equation.h"

Equation::Equation(long id, intVector ops) : 
    amountOfOperations(ops.size() - 1),
    operationScheme(ops.size() - 1) {
    independentTerm = id;
    operands = ops;
}

Equation::~Equation() {}

bool Equation::canBeSolved() {
    bool solved = false;

    while(!operationScheme.initialState() && !solved) {
        std::string scheme = operationScheme.toString();
        long result = operands[0];
        for(size_t i = 0; i < scheme.size(); i++) {
            if(scheme[i] == '0') {
                result += operands[i+1];
            } else {
                result *= operands[i +1];
            }
        }

        if(result == independentTerm) {
            solved = true;
        } else {
            operationScheme.add(1);
        }
    }
    return solved;
}

long Equation::getIndependentTerm() {
    return independentTerm;
}

void Equation::print(long result) {
    std::string scheme = operationScheme.toString();
    std::cout << operands[0];
    for(size_t i = 0; i < scheme.size(); i++) {
        if(scheme[i] == '0') {
            std::cout << " + " << operands[i+1];
        } else {
            std::cout << " * " << operands[i+1];
        }
    } 
    std::cout << " = " << result << " (" << independentTerm << ")" << std::endl;
}