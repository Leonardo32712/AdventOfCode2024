#include "../include/fileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    labMap labMap = fr.readLabMap();
    const stringVector originalMap = labMap.getMap();
    int loopCounter = 0;

    for(size_t i = 0; i < originalMap.size(); i++) {
        for(size_t j = 0; j < originalMap[i].size(); j++) {
            if(labMap.startSimulation(i,j)) {
                loopCounter++;
            }
            labMap.resetMap(originalMap);
        }
    }

    std::cout << "There are " << loopCounter << " distinct positions to make a loop." << std::endl;

    return 0;
}