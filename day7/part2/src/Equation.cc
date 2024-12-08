#include "../include/Equation.h"

Equation::Equation(long id, intVector ops) : 
    amountOfOperations(ops.size() - 1),
    operationScheme(ops.size() - 1, 3) {
    independentTerm = id;
    operands = ops;
}

Equation::~Equation() {}

bool Equation::canBeSolved() {
    bool solved = false;

    while(!operationScheme.initialState() && !solved) {
        if(operate() == independentTerm) {
            solved = true;
        } else {
            operationScheme.add(1);
        }
    }
    return solved;
}

long Equation::operate() {
    std::string scheme = operationScheme.toString();
    long result = operands[0];
    
    for(size_t i = 0; i < scheme.size(); i++) {
        if(scheme[i] == '0') {
            result += operands[i+1];
        } else if (scheme[i] == '1') {
            result *= operands[i+1];
        } else if (scheme[i] == '2') {
            std::string a = std::to_string(result);
            std::string b = std::to_string(operands[i+1]);
            result = stoll(a + b);
        }
    }

    return result;
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
        } else if(scheme[i] == '1') {
            std::cout << " * " << operands[i+1];
        } else if (scheme[i] == '2') {
            std::cout << " | " << operands[i+1];
        }
    } 
    std::cout << " = " << result << " (" << independentTerm << ")" << std::endl;
}