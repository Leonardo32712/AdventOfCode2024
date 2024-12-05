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

    std::string string = "";
    int result = 0;
    while (std::getline(file, string)) {
        result += stringToMultiplySum(string);
    }

    file.close();
    return result;
}

int stringToMultiplySum(std::string s) {
    std::regex rx(R"(mul\((\d+),(\d+)\))");
    auto matchesBegin = std::sregex_iterator(s.begin(), s.end(), rx);
    auto matchesEnd = std::sregex_iterator();

    int summary = 0;
    for (auto it = matchesBegin; it != matchesEnd; ++it) {
        std::smatch match = *it;
        summary += std::stoi(match.str(1))*std::stoi(match.str(2));
    }
    return summary;
}