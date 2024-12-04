#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef std::vector<int> intVector;

int safeReportsCounter(std::string);
bool analizeReport(intVector);
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
        if(analizeReport(stringToIntVector(stringReport))) {
            safeReportsCount++;
        }
    }

    file.close();
    return safeReportsCount;
}

bool analizeReport(intVector report) {
    if (report.size() < 2) {
        throw std::invalid_argument("Report must contain at least two numbers.");
    }

    int diff = report[1] - report[0];
    size_t i = 1;
    do {
        if ((diff > 0) != (report[i] > report[i - 1])) {
            return false;
        }

        diff = report[i] - report[i - 1];

        if (diff > 3 || diff < -3 || diff == 0) {
            return false;
        }

        i++;
    } while(i < report.size());

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