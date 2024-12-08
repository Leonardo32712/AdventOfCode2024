#include "../include/OpScheme.h"

OpScheme::OpScheme(size_t s, int b) : 
    operationSchemeNumber(0), 
    numberOfOperations(s),
    base(b) {};

OpScheme::~OpScheme() {};

void OpScheme::add(int sum) {
    operationSchemeNumber += sum;
}

bool OpScheme::initialState() {
    std::string opSchemeString = toString();
    
    if(opSchemeString.size() > numberOfOperations) {
        operationSchemeNumber = 0;
        return true;
    } else {
        return false;
    }
}

std::string OpScheme::toString() {
    long copy = operationSchemeNumber;
    std::string result = "";

    if (copy == 0) {
        return std::string(numberOfOperations, '0');
    }

    while (copy > 0) {
        result = (char)('0' + (copy % base)) + result;
        copy /= base;
    }

    if (result.length() < numberOfOperations) {
        result = std::string(numberOfOperations - result.length(), '0') + result;
    }

    return result;
}

