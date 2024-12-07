#include "../include/fileReader.h"

fileReader::fileReader(std::string fileName) {
    this->file.open(fileName);

    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }
}

fileReader::~fileReader() {
    this->file.close();
}

labMap fileReader::readLabMap() {
    std::string line;
    stringVector map;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        map.push_back(line);
    }

    labMap lm(map);
    return lm;
}
