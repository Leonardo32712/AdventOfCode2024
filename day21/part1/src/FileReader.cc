#include <sstream>
#include <algorithm>

#include "../include/FileReader.h"

fileReader::fileReader(std::string fileName) {
    this->file_.open(fileName);

    if (!file_) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }
}

fileReader::~fileReader() {
    this->file_.close();
}

StarShip fileReader::readStarShipCodes() {
    std::vector<std::string> codes;
    std::string line;
    
    while (std::getline(this->file_, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        codes.push_back(line);
    }

    return StarShip(codes);
}
