#include "fileReader.h"

fileReader::fileReader(std::string fileName) {
    this->file.open(fileName);

    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }
}

fileReader::~fileReader() {
    this->file.close();
}

void fileReader::readRules() {
    std::string line;
    bool readingRules = true;

    while (readingRules && std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if (line.empty()) {
            readingRules = false;
        } else {
            try {
                int first = std::stoi(line.substr(0, 2));
                int second = std::stoi(line.substr(3, 2));
                this->manual.emplaceRule(first, second);
            } catch (const std::exception& e) {
                std::cerr << "Error parsing line: " << line << " (" << e.what() << ")" << std::endl;
            }
        }
    }
}

void fileReader::readUpdatePages() {
    std::string line;
    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        if (!line.empty()) {
            std::vector<int> page;
            std::stringstream ss(line);
            std::string number;
            try {
                while (std::getline(ss, number, ',')) {
                    page.push_back(std::stoi(number));
                }
                this->manual.pushUpdatePages(page);
            } catch (const std::exception& e) {
                std::cerr << "Error parsing page line: " << line << " (" << e.what() << ")" << std::endl;
            }
        }
    }
}

safetyManual fileReader::readManual() {
    readRules();
    readUpdatePages();
    return this->manual;
}