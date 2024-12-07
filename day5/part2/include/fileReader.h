#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "safetyManual.h"

typedef std::vector<std::pair<int,int>> intPairVector;
typedef std::vector<std::vector<int>> intMatrix;

class fileReader {
private:
    std::ifstream file;
    safetyManual manual;

    void readRules();
    void readUpdatePages();
public:
    fileReader(std::string);
    ~fileReader();

    safetyManual readManual();
};

