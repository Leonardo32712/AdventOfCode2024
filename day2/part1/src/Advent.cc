#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef std::vector<int> intVector;

int safeReportsCounter(std::string);
bool analyzeReport(intVector);
intVector stringToIntVector(std::string);

int main(int argc, char const *argv[]) {

    std::cout << "There are " << safeReportsCounter(argv[1]) << " safe reports.";

    return 0;
}

int safeReportsCounter(std::string fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::ios_base::failure("Could not open file: " + fileName);
    }

    int safeReportsCount = 0;
    std::string stringReport = "";
    while (std::getline(file, stringReport)) {
        if(analyzeReport(stringToIntVector(stringReport))) {
            safeReportsCount++;
        }
    }

    file.close();
    return safeReportsCount;
}

bool analyzeReport(intVector report) {
    if (report.size() < 2) {
        throw std::invalid_argument("Report must contain at least two numbers.");
    }

    for(size_t i = 1; i < report.size() - 1; i++) {
        if ((report[i-1] > report[i]) != (report[i] > report[i + 1])) {
            return false;
        }

        if (std::abs(report[i-1] - report[i]) > 3 || std::abs(report[i] - report[i+1]) > 3) {
            return false;
        }

        if (report[i-1] - report[i] == 0 || report[i] - report[i+1] == 0) {
            return false;
        }
    }

    return true;
}

intVector stringToIntVector(std::string s) {
    std::stringstream ss(s);
    intVector numbers;

    int number = 0;
    while (ss >> number) { 
        numbers.push_back(number);
    }

    return numbers;
}