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
    int number = -1;
    int space = 0;
    
    for (int i = disk.size() - 1; i >= 0; i--) {
        if(disk[i] == -1) {
            if(space == 0) {
                number = disk[i];
            } else {
                if(firstFreeSpot(i + 1, space) != disk.size()) {
                    int freeSpot = firstFreeSpot(i + 1, space);
                    for(int j = 0; j < space; j++) {
                        std::swap(disk[freeSpot + j], disk[i + j + 1]);
                    }
                }
                number = disk[i];
                space = 1;
            }
        } else {
            if(space == 0) {
                space++;
                number = disk[i];
            } else if(disk[i] == number) {
                space++;
            } else {
                if(firstFreeSpot(i + 1, space) != disk.size()) {
                    int freeSpot = firstFreeSpot(i + 1, space);
                    for(int j = 0; j < space; j++) {
                        std::swap(disk[freeSpot + j], disk[i + j + 1]);
                    }
                }
                number = disk[i];
                space = 1;
            }
        }
    }
}

long long DiskMap::getChecksum() {
    unzipDisk();
    moveFiles();
    long long checkSum = 0;

    for (size_t i = 0; i < disk.size(); i++) {
        if(disk[i] != -1) {
            checkSum += disk[i] * i;
        }
    }

    return checkSum;
}

size_t DiskMap::firstFreeSpot(int max, int size) {
    int freeSpaceCounter = 0;
    for(size_t i = 0; i < static_cast<size_t>(max); i++) {
        if(disk[i] == -1) {
            freeSpaceCounter++;
        } else {
            freeSpaceCounter = 0;
        }

        if(freeSpaceCounter >= size) {
            return i - size + 1;
        }
    }
    return disk.size();
}

void DiskMap::printDisk() {
    for( int number : disk) {
        number == -1 ? std::cout << '.' : std::cout << number;
    }
    std::cout << std::endl;
}