#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

typedef std::vector<std::string> stringVector;
typedef std::set<std::string> stringSet;

class Onsen {
    private:
        const stringSet patterns;
        const stringVector desings;

        long countPatternBuilds(const std::string&);
    public:
        Onsen(stringSet, stringVector);
        ~Onsen();

        long possibleDesigns();
        void printOnsen();
};