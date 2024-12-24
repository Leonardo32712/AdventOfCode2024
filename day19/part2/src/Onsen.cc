#include "../include/Onsen.h"

Onsen::Onsen(stringSet p, stringVector d) : 
        patterns(p),
        desings(d) {}

Onsen::~Onsen() {}

long Onsen::possibleDesigns() {
    long count = 0;
    for (size_t i = 0; i < desings.size(); i++) {
        count += countPatternBuilds(desings[i]);
    }
    return count;
}

long Onsen::countPatternBuilds(const std::string& s) {
    std::vector<long> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= static_cast<int>(s.size()); ++i) {
        for (int j = 0; j < i; ++j) {
            std::string sub = s.substr(j, i - j);
            if (patterns.count(sub)) {
                dp[i] += dp[j];
            }
        }
    }

    return dp[s.size()];
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