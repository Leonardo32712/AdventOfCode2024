#include "../include/Solutions.h"

Solutions::Solutions() {}

Solutions::~Solutions() {}

long2 Solutions::getResult(long2 stone, int blinks) {
    for( Solution s: solutions) {
        if(s.stone == stone && s.blinks == blinks) {
            return s.result;
        }
    }
    return -1;
}

void Solutions::saveResult(long2 stone, int blinks, long2 result) {
    if(getResult(stone, blinks) == -1) {
        solutions.push_back(Solution{stone, blinks, result});
    }
}