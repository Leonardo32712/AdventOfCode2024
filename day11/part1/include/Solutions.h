#include <iostream>
#include <string>
#include <vector>
#include <cmath>

typedef long long long2;

struct Solution {
    long2 stone;
    int blinks;
    long2 result;
};

typedef long long long2;

class Solutions {
    private:
        std::vector<Solution> solutions;

    public:
        Solutions();
        ~Solutions();

        long2 getResult(long2, int);
        void saveResult(long2, int, long2);
};
