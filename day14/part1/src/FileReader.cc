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

std::vector<Robot> fileReader::readRobots() {
    std::string line;
    std::vector<Robot> Robots;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        intPair p, v;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &p.first, &p.second, &v.first, &v.second);
        Robots.emplace_back(p,v);
    }

    return Robots;
}
