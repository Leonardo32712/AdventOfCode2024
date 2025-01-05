#pragma once

#include <vector>
#include <set>
#include <map>

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

using intPair = std::pair<int, int>;

class StarShip {
    private:
        std::vector<std::string> codes;

    public:
        StarShip(std::vector<std::string>);
        ~StarShip();

        void printCodes();
};