#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int readFile(std::string);
int stringToMultiplySum(std::string);

int main(int argc, char const *argv[]) {

    std::cout << "The multiply result is " << readFile(argv[1]) << ".";

    return 0;
}

int readFile(std::string fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }

    std::string input = "";
    std::string line = "";    
    int result = 0;
    while (std::getline(file, line)) {
        input += line;
    }

    result = stringToMultiplySum(input);
    file.close();
    return result;
}

int stringToMultiplySum(std::string s) {
    std::regex xp(R"(mul\((\d+),(\d+)\)|(do\(\))|(don't\(\)))");

    auto xpBegin = std::sregex_iterator(s.begin(), s.end(), xp);
    auto xpEnd = std::sregex_iterator();
    bool processMul = true;
    int summary = 0;

    for (auto it = xpBegin; it != xpEnd; ++it) {
        std::smatch xpMatch = *it;

        if (xpMatch.str() == "do()") {
            processMul = true;
        } else if (xpMatch.str() == "don't()") {
            processMul = false;
        } else if (processMul) {
            summary += std::stoi(xpMatch.str(1))*std::stoi(xpMatch.str(2));
        }
    }
    return summary;
}