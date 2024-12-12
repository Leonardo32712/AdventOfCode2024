#include <vector>
#include <iostream>
#include <string>

typedef std::vector<std::string> stringVector;
typedef std::pair<int,int> areaPerimeter;

class Garden {
    private:
        stringVector gardenMap;

        void exploreRegion(int, int, char, areaPerimeter&);
        void checkPlot(int, int, char, areaPerimeter&);
        bool outOfBounds(int, int);
    public:
        Garden(stringVector);
        ~Garden();

        int totalPrice();
        void printGarden();
};