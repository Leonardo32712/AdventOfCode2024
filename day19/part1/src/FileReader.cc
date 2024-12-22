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

Onsen fileReader::readOnsen() {
    stringVector patterns;
    stringVector desings;
    std::string line;
    bool readingPatterns = true;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if (line.empty()) {
            readingPatterns = false;
        } else if (readingPatterns) {
            size_t start = 0, end;
            while ((end = line.find(',', start)) != std::string::npos) {
                patterns.push_back(line.substr(start, end - start));
                start = end + 1;
            }
            patterns.push_back(line.substr(start));
        } else {
            desings.push_back(line);
        }
    }

    return Onsen(patterns, desings);
}