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

std::vector<ClawMachine> fileReader::readClawMachines() {
    std::string line;
    std::vector<ClawMachine> clawMachines;

    while (std::getline(this->file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        if (line.find("Button A:") == 0) {
            int buttonAX, buttonAY;
            sscanf(line.c_str(), "Button A: X+%d, Y+%d", &buttonAX, &buttonAY);

            if (std::getline(this->file, line)) {
                int buttonBX, buttonBY;
                sscanf(line.c_str(), "Button B: X+%d, Y+%d", &buttonBX, &buttonBY);

                if (std::getline(this->file, line)) {
                    int prizeX, prizeY;
                    sscanf(line.c_str(), "Prize: X=%d, Y=%d", &prizeX, &prizeY);

                    clawMachines.emplace_back(
                        doublePair(buttonAX, buttonAY),
                        doublePair(buttonBX, buttonBY),
                        doublePair(prizeX, prizeY)
                    );
                }
            }
        }
    }

    return clawMachines;
}
