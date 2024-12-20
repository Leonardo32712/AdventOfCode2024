#include "../include/FileReader.h"

fileReader::fileReader(std::string fileName) {
    this->file.open(fileName);

    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }
}

fileReader::~fileReader() {
    this->file.close();
}

Computer fileReader::readPC() {
    longVector registers;
    longVector program;
    std::string line;
    bool readingRegisters = true;
    
    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if(line.empty()) {
            readingRegisters = false;
        }

        if(readingRegisters) {
            std::istringstream iss(line);
            std::string label, regName;
            int value;

            iss >> label >> regName;
            iss.ignore(1, ':');
            iss >> value;

            registers.push_back(value);
        } else {
            line.erase(0, 9);
            std::istringstream iss(line);
            int instruction;

            while (iss >> instruction) {
                program.push_back(instruction);
                if (iss.peek() == ',') {
                    iss.ignore(); 
                }
            }
        }
    }

    return Computer(registers, program);
}
