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

TopographicMap fileReader::readTopographicMap() {
    std::string line;
    intMatrix map({});

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        intVector intLine({});
        for(char digit : line) {
            if(digit - '0' < 0 || digit - '0' > 9) {
                std::cout << "Error reading digit '" << digit << "'" << std::endl;
                throw std::runtime_error("Error reading digit.");
            }

            intLine.push_back(digit - '0');
        }

        map.push_back(intLine);
    }

    return TopographicMap(map);
}
