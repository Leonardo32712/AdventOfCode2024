#include "../include/DiskMap.h"

DiskMap::DiskMap(intVector d) {
    this->disk = d;
}

DiskMap::~DiskMap() {}

void DiskMap::unzipDisk() {
    intVector unzipedDisk({});
    bool readingBlock(true);

    for(size_t i = 0; i < disk.size(); i++) {
        long fillNum = readingBlock ? i/2 : -1;
        int repeatCount = disk[i];
        for(int j = 0; j < repeatCount; j++) {
            unzipedDisk.push_back(fillNum);
        }
        readingBlock = !readingBlock;
    }

    disk = std::move(unzipedDisk);
}

void DiskMap::moveFiles() {
    size_t freeSpot = firstFreeSpot();
    for (size_t i = disk.size(); i-- > freeSpot;) {
        if (disk[i] != -1) {
            std::swap(disk[freeSpot], disk[i]);
            freeSpot = firstFreeSpot();
        }
    }
}

long long DiskMap::getChecksum() {
    unzipDisk();
    moveFiles();
    long long checkSum = 0;

    for (size_t i = 0; i < firstFreeSpot(); i++) {
        checkSum += disk[i] * i;
    }

    return checkSum;
}

size_t DiskMap::firstFreeSpot() {
    for(size_t i = 0; i < disk.size(); i++) {
        if(disk[i] == -1) {
            return i;
        }
    }
    return -1;
}

void DiskMap::printDisk() {
    for( int number : disk) {
        number == -1 ? std::cout << '.' : std::cout << number;
    }
    std::cout << std::endl;
}