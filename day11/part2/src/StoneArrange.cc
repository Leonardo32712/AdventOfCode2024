#include "../include/StoneArrange.h"

StoneArrange::StoneArrange(longVector s) : stones(s) {}

StoneArrange::~StoneArrange() {}

long2 StoneArrange::blink(const int blinks) {
    long2 stonesCount = 0;

    for (const long2& stone : stones) {
        stonesCount += countResult(stone, blinks);
    }

    return stonesCount;
}

long2 StoneArrange::countResult(long2 stone, int blinks) {
    if(blinks == 0) { return 1; }

    const long2 savedResult = cacheSolutions.getResult(stone, blinks);
    if(savedResult != -1) {
        return savedResult;
    }

    long2 result;
    if (stone == 0) {
        result = countResult(1, blinks - 1);
    } else if (countDigits(stone) % 2 == 0) {
        longPair splitedNumber = splitNumber(stone);
        result = countResult(splitedNumber.first, blinks - 1) + countResult(splitedNumber.second, blinks - 1);
    } else {
        result = countResult(stone*2024, blinks - 1);
    }

    cacheSolutions.saveResult(stone, blinks, result);
    return result;
}

longPair StoneArrange::splitNumber(long2 number) {
    int halfDigitsCount = countDigits(number) / 2;
    long divisor = 1;

    for (int i = 0; i < halfDigitsCount; ++i) {
        divisor *= 10;
    }

    return longPair(number / divisor, number % divisor);
}

int StoneArrange::countDigits(long2 number) {
    return std::to_string(number).length();
}

void StoneArrange::printStones() {
    std::cout << "Stones: ";
    for(size_t i = 0; i < stones.size(); i++) {
        std::cout << stones[i] << " ";
    }
    std::cout << std::endl;
}