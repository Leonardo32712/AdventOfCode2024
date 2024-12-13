#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <set>

typedef std::vector<std::string> stringVector;
typedef std::pair<int,int> intPair;

enum Side {
    NONE = 0,
    DOWN = 1,
    RIGHT = 2,
    UP = 3,
    LEFT = 4,
};

class Garden {
    private:
        stringVector gardenMap;
        std::set<intPair> perimeterCoords;

        int calculatePerimeter();
        int exploreRegion(const int, const int, const char);
        bool checkPlot(int, int, char);
        bool outOfBounds(int, int);
    public:
        Garden(stringVector);
        ~Garden();

        int totalPrice();
        void printGarden();
};