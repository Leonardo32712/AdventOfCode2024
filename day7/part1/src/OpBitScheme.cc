#include "../include/OpBitScheme.h"

OpBitScheme::OpBitScheme(size_t s) : number(0b0), size(s) {};

OpBitScheme::~OpBitScheme() {};

void OpBitScheme::add(int sum) {
    number += sum;
}

void OpBitScheme::setBit(int pos) {
    number |= (1 << pos);
}

unsigned int OpBitScheme::getBit(int pos) {
    return (number >> pos) & 1;
}

bool OpBitScheme::initialState() {
    std::string binaryString = std::bitset<BIT_SIZE>(number).to_string();

    if(binaryString.find_first_of('1') == binaryString.size() - size - 1) {
        return true;
    } else {
        return false;
    }
}

std::string OpBitScheme::toString() {
    std::string binaryString = std::bitset<BIT_SIZE>(number).to_string();
    return binaryString.substr(BIT_SIZE - size);
}