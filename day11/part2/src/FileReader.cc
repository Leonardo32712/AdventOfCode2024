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

StoneArrange fileReader::readStoneArrange() {
    std::string line;
    longVector stones;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string number;
            try {
                while (std::getline(ss, number, ' ')) {
                    stones.push_back(std::stol(number));
                }
            } catch (const std::exception& e) {
                std::cerr << "Error parsing stone: " << line << " (" << e.what() << ")" << std::endl;
            }
        }
    }

    return StoneArrange(stones);
}
