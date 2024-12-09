#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "CityMap.h"

typedef std::vector<std::pair<int,int>> intPairVector;
typedef std::vector<std::vector<int>> intMatrix;

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    CityMap readCityMap();
};

