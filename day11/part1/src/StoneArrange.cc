#include "../include/StoneArrange.h"

StoneArrange::StoneArrange(intVector s) {
    stones = s;
    timesBlinked = 0;
}

StoneArrange::~StoneArrange() {}

size_t StoneArrange::getStonesCount() {
    return stones.size();
}

void StoneArrange::printStones() {
    std::cout << "After " << timesBlinked << " blinks:" << std::endl;
    std::cout << "Stones: ";
    for(size_t i = 0; i < stones.size(); i++) {
        std::cout << stones[i] << " ";
    }
    std::cout << std::endl << "Stones count: " << getStonesCount() << std::endl << std::endl;
}