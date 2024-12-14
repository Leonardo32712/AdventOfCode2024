#include "../include/Solutions.h"

Solutions::Solutions() {}

Solutions::~Solutions() {}

long2 Solutions::getResult(long2 stone, int blinks) {
    auto s = solutions.find(keyLongInt(stone, blinks));
    return s != solutions.end() ? s->second : -1;
}

void Solutions::saveResult(long2 stone, int blinks, long2 result) {
    if(getResult(stone, blinks) == -1) {
        solutions[keyLongInt(stone, blinks)] = result;
    }
}