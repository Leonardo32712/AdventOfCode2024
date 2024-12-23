#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

typedef std::vector<std::string> stringVector;
typedef std::set<std::string> stringSet;
typedef std::unordered_map<std::string, bool> stringMap;

class Onsen {
    private:
        const stringSet patterns;
        stringMap patternsCache;
        const stringVector desings;

        void resetCache();
        bool dfs(const std::string&);
    public:
        Onsen(stringSet, stringVector);
        ~Onsen();

        int possibleDesigns();
        void printOnsen();
};