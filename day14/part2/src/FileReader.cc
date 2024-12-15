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

RobotSimulator fileReader::readRobots() {
    std::string line;
    std::vector<Robot> robots;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        intPair p, v;
        sscanf(line.c_str(), "p=%d,%d v=%d,%d", &p.first, &p.second, &v.first, &v.second);
        robots.emplace_back(p,v);
    }

    return RobotSimulator(robots);
}
