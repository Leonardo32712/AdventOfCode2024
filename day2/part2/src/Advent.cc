#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef std::vector<int> intVector;

int safeReportsCounter(std::string);
intVector stringToIntVector(std::string);
bool analyzeReport(const intVector&, bool);
bool checkDampener(const intVector&, size_t, bool);
bool analyzeWithDampener(const intVector&, size_t);
bool analyzeWithRelativePosition(const intVector&, size_t, int);

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
        if(analyzeReport(stringToIntVector(stringReport), false)) {
            safeReportsCount++;
        }
    }

    file.close();
    return safeReportsCount;
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

bool analyzeReport(const intVector& report, bool dampener) {
    if (report.size() < 2) {
        throw std::invalid_argument("Report must contain at least two numbers.");
    }

    for(size_t i = 1; i < report.size() - 1; i++) {
        if ((report[i-1] > report[i]) != (report[i] > report[i + 1])) {
            return checkDampener(report, i, dampener);
        }

        if (std::abs(report[i-1] - report[i]) > 3 || std::abs(report[i] - report[i+1]) > 3) {
            return checkDampener(report, i, dampener);
        }

        if (report[i-1] - report[i] == 0 || report[i] - report[i+1] == 0) {
            return checkDampener(report, i, dampener);
        }
    };

    return true;
}

bool checkDampener(const intVector& report, size_t i, bool dampener) {
    if(!dampener) {
        return analyzeWithDampener(report, i);
    } else {
        return false;
    }
}

bool analyzeWithDampener(const intVector& report, size_t i) {
    return analyzeWithRelativePosition(report, i, -1) || 
            analyzeWithRelativePosition(report, i, 0) || 
            analyzeWithRelativePosition(report, i, +1);
}

bool analyzeWithRelativePosition(const intVector& report, size_t i, int relativePosition) {
    intVector newReport = report;
    newReport.erase(newReport.begin() + i + relativePosition);

    return analyzeReport(newReport, true);
}