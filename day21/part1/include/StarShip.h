#pragma once

#include <vector>
#include <string>

#include "Constants.h"
#include "KeyPad.h"

class StarShip {
    private:
        std::vector<std::string> codes;
        std::vector<KeyPad> keyPads;

        std::string getInstructions(char, size_t);
        int codeToInt(std::string);
        void resetKeyPads();
    public:
        StarShip(std::vector<std::string>);
        ~StarShip();

        long getComplexitySum();
        void printCodes();
};