#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <set>

typedef std::vector<std::string> stringVector;
typedef std::pair<int,int> intPair;

class Garden {
    private:
        stringVector gardenMap;

        intPair exploreRegion(const int, const int, const char);
        int checkCorners(const int, const int, const char);
        bool checkCorner(const intPair, const intPair, const char);
        bool checkPlot(int, int, char);
        bool outOfBounds(int, int);
    public:
        Garden(stringVector);
        ~Garden();

        int totalPrice();
        void printGarden();
};