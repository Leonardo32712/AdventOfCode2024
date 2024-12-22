#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef std::vector<std::string> stringVector;

class Onsen {
    private:
        const stringVector patterns;
        const stringVector desings;

    public:
        Onsen(stringVector, stringVector);
        ~Onsen();

        void printOnsen();
};