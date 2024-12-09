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

DiskMap fileReader::readDiskMap() {
    std::string line;
    intVector disk({});

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        for(char digit : line) {
            disk.push_back(digit - '0');
        }
    }

    return DiskMap(disk);
}
