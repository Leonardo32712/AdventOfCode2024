#include "../include/FileReader.h"

FileReader::FileReader(std::string fileName) {
    this->file.open(fileName);

    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }
}

FileReader::~FileReader() {
    this->file.close();
}

equationVector FileReader::readEquations() {
    std::string line;
    equationVector equations({});

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        equations.push_back(stringToEquation(line));
    }


    return equations;
}

Equation FileReader::stringToEquation(const std::string input) {
    long independentTerm = 0;
    intVector operands;

    size_t colonPos = input.find(':');
    independentTerm = std::stoll(input.substr(0, colonPos));

    std::string operandsPart = input.substr(colonPos + 1);
    std::stringstream ss(operandsPart);
    std::string number;

    while (ss >> number) {
        operands.push_back(std::stoi(number));  
    }

    return Equation(independentTerm, operands);
}
