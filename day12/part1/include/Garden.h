#include <vector>
#include <iostream>
#include <string>

typedef std::vector<std::string> stringVector;

class Garden {
    private:
        stringVector gardenMap;

        bool outOfBounds(size_t, size_t);
    public:
        Garden(stringVector);
        ~Garden();

        void printGarden();
};
