#pragma once

#include <vector>
#include <set>
#include <map>

struct ShortCut;
enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

using intPair = std::pair<int, int>;
using coordsSet = std::set<intPair>;
using ShortCutSet = std::set<ShortCut>;

struct ShortCut {
    intPair firstCoord;
    intPair secondCoord;
    long timeDifference;

    bool operator<(const ShortCut& other) const {
        return std::tie(firstCoord, secondCoord, timeDifference) <
               std::tie(other.firstCoord, other.secondCoord, other.timeDifference);
    }
};

class Race {
    private:
        std::vector<std::string> raceMap;
        std::map<intPair, int> path;

        intPair findPathStart();
        void savePathData(intPair);
        void exploreShortCut(intPair, intPair, ShortCutSet&);

        intPair moveCoord(intPair, Direction);
        bool canMove(intPair, Direction);
        bool canMoveTo(intPair);
        bool outOfBounds(intPair);
        bool isWall(intPair);
    public:
        Race(std::vector<std::string>);
        ~Race();

        ShortCutSet getPathShortCuts();
        int getShortCutsCountByMinTimeSaved(int);
        void printShortCutsByTime();
        void printMap();
};