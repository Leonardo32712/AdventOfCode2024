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
    intPairVector memory;
    std::string line;
    
    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if(!line.empty()) {
            int first, second;
            sscanf(line.c_str(), "%d,%d", &first, &second);
            memory.push_back(intPair(first,second));
        }
    }

    return Computer(memory);
}
