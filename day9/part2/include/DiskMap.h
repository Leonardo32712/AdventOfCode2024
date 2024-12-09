#include <vector>
#include <iostream>
#include <string>

typedef std::vector<int> intVector;

class DiskMap {
    private:
        intVector disk;

        void unzipDisk();
        void moveFiles();
        size_t firstFreeSpot(int, int);
    public:
        DiskMap(intVector);
        ~DiskMap();

        long long getChecksum();
        void printDisk();
};
