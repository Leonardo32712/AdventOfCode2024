#include "../include/Onsen.h"

Onsen::Onsen(stringSet p, stringVector d) : 
        patterns(p),
        desings(d) {
    
    for (const std::string& pat : patterns) {
        patternsCache[pat] = true;
    }
}

Onsen::~Onsen() {}

int Onsen::possibleDesigns() {
    int count = 0;
    resetCache();

    for (size_t i = 0; i < desings.size(); i++) {
        if (dfs(desings[i])) {
            count++;
        }
    }
    return count;
}

bool Onsen::dfs(const std::string& s) {
    if (patternsCache.find(s) != patternsCache.end()) {
        return patternsCache[s];
    }

    if (s.size() <= 1) {
        patternsCache[s] = false;
        return false;
    }

    for (size_t i = 1; i < s.size(); i++) {
        const std::string first = s.substr(0, i);
        const std::string second = s.substr(i);

        if (dfs(first) != 0 && dfs(second) != 0) {
            patternsCache[s] = true;
            return true;
        } else {
            patternsCache[s] = false;
        }
    }

    patternsCache[s] = false;
    return false;
}

void Onsen::resetCache() {
    patternsCache.clear();
    for (const auto& pat : patterns) {
        patternsCache[pat] = true;
    }
}

void Onsen::printOnsen() {
    for(std::string p : patterns) {
        std::cout << p << ", ";
    }

    std::cout << std::endl << std::endl;

    for(std::string d : desings) {
        std::cout << d << std::endl;
    }
}