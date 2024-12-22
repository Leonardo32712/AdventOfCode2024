#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef std::pair<int,int> intPair;
typedef std::vector<intPair> intPairVector;
typedef std::vector<std::string> charMatrix;

const int MAX_MEMORY_SPACE = 70;
const intPair END_COORDS = intPair(MAX_MEMORY_SPACE, MAX_MEMORY_SPACE);

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

struct State {
    intPair coords;
    long cost;

    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

class Computer {
    private:
        const intPairVector corruptedMemory;

        long getBestPath(intPairVector);
        intPair moveCoord(intPair, Direction);
        Direction rotateDirectionRight(Direction, int);
        bool outOfBounds(intPair);
        bool isCorrupted(intPair, intPairVector);
    public:
        Computer(intPairVector);
        ~Computer();

        intPair getFirstBlock();
        long simulate(int);
        void printCorrupted();
        void printMemorySpace();
};