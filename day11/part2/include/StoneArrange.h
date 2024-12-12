#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Solutions.h"

typedef std::vector<long2> longVector;
typedef std::pair<long2, long2> longPair;

class StoneArrange {
    private:
        const longVector stones;
        Solutions cacheSolutions;

        int countDigits(long2);
        longPair splitNumber(long2);
        long2 countResult(long2, int);
    public:
        StoneArrange(longVector);
        ~StoneArrange();

        long2 blink(const int);
        void printStones();
};
