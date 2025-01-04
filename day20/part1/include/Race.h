#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <limits>

typedef std::pair<int,int> intPair;
typedef std::pair<intPair,intPair> coordsPair;
typedef std::pair<bool,bool> doubleCheck;
typedef std::vector<intPair> coordsVector;
typedef std::set<intPair> coordsSet;

struct ShortCut {
    intPair firstCoord;
    intPair secondCoord;
    long timeDifference;

    bool operator<(const ShortCut& other) const {
        return std::tie(firstCoord, secondCoord, timeDifference) <
               std::tie(other.firstCoord, other.secondCoord, other.timeDifference);
    }
};

typedef std::set<ShortCut> ShortCutSet;

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

class Race {
    private:
        std::vector<std::string> raceMap;
        std::vector<intPair> path;
        std::map<intPair, int> pathTimes;
        intPair pathStart;
        long shortCutLessScore;

        intPair findPathStart();
        void savePathTimes();
        void exploreShortCut(intPair, intPair, ShortCutSet&);

        bool checkIfBetterShortCut(ShortCut, const ShortCutSet&);
        bool canMove(intPair, Direction);
        bool canMove(intPair);
        bool outOfBounds(intPair);
        bool isWall(intPair);
        intPair moveCoord(intPair, Direction);
        void rotateDirectionRight(Direction&, int);
    public:
        Race(std::vector<std::string>);
        ~Race();

        ShortCutSet getPathShortCuts();
        int getShortCutsByMinTimeSave(int);
        void printShortCutsByTime(const ShortCutSet&);
        void printRaceWithShorcutAndVisited(const ShortCut&, const std::set<intPair>&, const ShortCutSet&);
        void printMap();
};