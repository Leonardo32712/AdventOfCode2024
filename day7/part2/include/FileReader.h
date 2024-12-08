#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

#include "../include/Equation.h"

typedef std::vector<Equation> equationVector;

class FileReader {
private:
    std::ifstream file;
    Equation stringToEquation(std::string);
public:
    FileReader(std::string);
    ~FileReader();

    equationVector readEquations();
};
