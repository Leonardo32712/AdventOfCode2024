#include <vector>
#include <iostream>
#include <string>

typedef std::vector<int> intVector;
typedef std::vector<intVector> intMatrix;

class TopographicMap {
    private:
        intMatrix map;

    public:
        TopographicMap(intMatrix);
        ~TopographicMap();

        long long getScoreSum();
        void printMap();
};
