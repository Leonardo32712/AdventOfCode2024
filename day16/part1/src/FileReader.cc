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

Maze fileReader::readMaze() {
    std::vector<std::string> mazeMap;
    std::string line;
    
    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        mazeMap.push_back(line);
    }

    return Maze(mazeMap);
}
