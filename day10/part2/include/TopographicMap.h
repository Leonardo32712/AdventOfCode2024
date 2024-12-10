#include <vector>
#include <iostream>
#include <string>

typedef std::pair<size_t, size_t> coord;
typedef std::vector<coord> coordVector;
typedef std::vector<int> intVector;
typedef std::vector<intVector> intMatrix;

class TopographicMap {
    private:
        intMatrix map;
        intVector trailHeads;

        void findTrailHeads();
        bool checkNextStep(size_t, size_t, int&);
        bool outOfBounds(size_t, size_t);
    public:
        TopographicMap(intMatrix);
        ~TopographicMap();

        long getRatingSum();
        void printMap();
};
