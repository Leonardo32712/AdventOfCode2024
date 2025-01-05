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

Race fileReader::readRace() {
    std::vector<std::string> raceMap;
    std::string line;
    
    while (std::getline(this->file_, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        raceMap.push_back(line);
    }

    return Race(raceMap);
}
