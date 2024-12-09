#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    DiskMap dm (fr.readDiskMap());

    long long checkSum = dm.getChecksum();
    std::cout << "Checksum: " << checkSum << std::endl;
    return 0;
}

