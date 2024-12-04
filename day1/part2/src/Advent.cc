#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<int> intVector;
typedef std::pair<intVector, intVector> pairIntVector;

pairIntVector readSortedDistances(std::string fileName);
void insertDistanceSorting(intVector &vector, int distance);
int addDistanceDifference(pairIntVector distanceLists);
int addDistanceRepetitions(pairIntVector distanceLists);

int main(int argc, char const *argv[]) {

    pairIntVector sortedDistanceLists = readSortedDistances(argv[1]);
    std::cout << "The total distance difference is " << addDistanceDifference(sortedDistanceLists) << std::endl;
    std::cout << "The similarity score is " << addDistanceRepetitions(sortedDistanceLists);

    return 0;
}

pairIntVector readSortedDistances(std::string fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }

    std::string stringDistance = "";
    pairIntVector distanceLists;
    bool isLeftDistance = true;
    while (file >> stringDistance) {
        if(isLeftDistance) {
            insertDistanceSorting(distanceLists.first, std::stoi(stringDistance));
            isLeftDistance = false;
        } else {
            insertDistanceSorting(distanceLists.second, std::stoi(stringDistance));
            isLeftDistance = true;
        }
    }

    file.close();
    return distanceLists;
}

void insertDistanceSorting(intVector &vector, int distance) {
    auto it = std::lower_bound(vector.begin(), vector.end(), distance);
    vector.insert(it, distance);
    return;
}

int addDistanceDifference(pairIntVector distanceLists) {
    if(distanceLists.first.size() != distanceLists.second.size()) {
        throw std::invalid_argument("Size of left and right distance lists are different.");
    }

    int summary = 0;
    for(int i = 0; i < int(distanceLists.first.size()); i++) {
        summary += std::abs(distanceLists.first[i] - distanceLists.second[i]);
    }
    return summary;
}

int addDistanceRepetitions(pairIntVector distanceLists) {
    int summary = 0;
    for(int i = 0; i < int(distanceLists.first.size()); i++) {
        int actualDistance = distanceLists.first[i];
        int count = std::count(distanceLists.second.begin(), distanceLists.second.end(), actualDistance);
        summary += actualDistance * count;
    }
    return summary;
}