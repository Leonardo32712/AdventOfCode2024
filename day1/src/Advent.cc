#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::vector<int> intVector;
typedef std::pair<intVector, intVector> pairIntVector;

pairIntVector readSortedDistances(std::string fileName);
void insertDistanceSorting(intVector &vector, int number);
int addNumbers(pairIntVector numberLists);

int main(int argc, char const *argv[]) {

    pairIntVector sortedNumberLists = readSortedDistances(argv[1]);
    int totalDistance = addNumbers(sortedNumberLists);

    std::cout << "The total distance is " << totalDistance;

    return 0;
}

pairIntVector readSortedDistances(std::string fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }

    std::string stringNumber = "";
    pairIntVector numberLists;
    bool isLeftNumber = true;
    while (file >> stringNumber) {
        if(isLeftNumber) {
            insertDistanceSorting(numberLists.first, std::stoi(stringNumber));
            isLeftNumber = false;
        } else {
            insertDistanceSorting(numberLists.second, std::stoi(stringNumber));
            isLeftNumber = true;
        }
    }

    file.close();
    return numberLists;
}

void insertDistanceSorting(intVector &vector, int number) {
    auto it = std::lower_bound(vector.begin(), vector.end(), number);
    vector.insert(it, number);
    return;
}

int addNumbers(pairIntVector numberLists) {
    if(numberLists.first.size() != numberLists.second.size()) {
        throw std::invalid_argument("Size of left and right number lists are different.");
    }

    int summary = 0;
    for(int i = 0; i < int(numberLists.first.size()); i++) {
        summary += std::abs(numberLists.first[i] - numberLists.second[i]);
    }
    return summary;
}