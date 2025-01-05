#pragma once

#include <vector>
#include <map>
#include <string>

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

using intPair = std::pair<int, int>;

class KeyPad {
    private:
        std::vector<std::string> pad;
        std::map<char, intPair> padCoords;
        intPair currentPosition;

        void safePadCoords();
        intPair moveCoords(intPair, Direction);
        void vertical(intPair, std::string&);
        void horizontal(intPair, std::string&);
        bool canMove(Direction);
        bool outOfPad(intPair);
    public:
        KeyPad(bool);
        ~KeyPad();

        void resetCurrentPosition();
        std::string moveTo(char);
        void printCodes();
};