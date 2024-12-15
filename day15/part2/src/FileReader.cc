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

Warehouse fileReader::readRobots() {
    std::vector<std::string> warehouseMap;
    std::vector<Direction> robotMoveProgram;
    std::string line;
    bool readingMap = true;
    
    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if(line == "") {
            readingMap = false;
        }

        if(readingMap) {
            warehouseMap.push_back(line);
        } else {
            for(char d : line) {
                switch (d) {
                    case '^':
                        robotMoveProgram.push_back(UP);
                        break;
                    case '>':
                        robotMoveProgram.push_back(RIGHT);
                        break;
                    case 'v':
                        robotMoveProgram.push_back(DOWN);
                        break;
                    case '<':
                        robotMoveProgram.push_back(LEFT);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return Warehouse(warehouseMap, robotMoveProgram);
}
