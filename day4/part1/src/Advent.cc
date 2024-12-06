#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::vector<std::string> stringVector;

void read_file(std::string);
stringVector get_XMAS_ocurrences(const stringVector&);
void print_result(const stringVector&, const int&);
void mark_horizontals(const stringVector&, stringVector&, int&);
void mark_verticals(const stringVector&, stringVector&, int&);
void mark_diagonals(const stringVector&, stringVector&, int&);
void mark_diagonals_secondary(const stringVector&, stringVector&, int&);

int main(int argc, char const *argv[]) {

    read_file(argv[1]);
    
    return 0;
}

void read_file(std::string file_name) {
    std::ifstream file(file_name);
    if (!file) {
        throw std::ios_base::failure("Could not open file: " + file_name);
    }

    stringVector input = {};

    std::string line = "";
    while (std::getline(file, line)) {
        input.push_back(line);
    }

    file.close();

    get_XMAS_ocurrences(input);
}

stringVector get_XMAS_ocurrences(const stringVector& original) {
    stringVector result(original.size(), std::string(original[0].size() - 1,'.'));
    int ocurrences_counter = 0;

    mark_horizontals(original, result, ocurrences_counter);
    mark_verticals(original, result, ocurrences_counter);
    mark_diagonals(original, result, ocurrences_counter);
    mark_diagonals_secondary(original, result, ocurrences_counter);
    
    print_result(result, ocurrences_counter);

    return result;
}

void print_result(const stringVector& result, const int& counter) {
    for(size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
    std::cout << "The result is " << counter << ".";
}

void mark_horizontals(const stringVector& original, stringVector& result, int& counter) {
    for(size_t i = 0; i < original.size(); i++) {
        for(size_t j = 0; j < original[i].size() - 3; j++) {
            std::string word = original[i].substr(j,4);
            if(word == "XMAS") {
                result[i][j] = 'X';
                result[i][j+1] = 'M';
                result[i][j+2] = 'A';
                result[i][j+3] = 'S';
                counter++;
            } else if(word == "SAMX") {
                result[i][j] = 'S';
                result[i][j+1] = 'A';
                result[i][j+2] = 'M';
                result[i][j+3] = 'X';
                counter++;
            }
        }
    }
}

void mark_verticals(const stringVector& original, stringVector& result, int& counter) {
    for(size_t i = 0; i < original.size() - 3; i++) {
        for(size_t j = 0; j < original[i].size(); j++) {
            std::string word;
            word.push_back(original[i][j]);
            word.push_back(original[i+1][j]);
            word.push_back(original[i+2][j]);
            word.push_back(original[i+3][j]);
            if(word == "XMAS") {
                result[i][j] = 'X';
                result[i+1][j] = 'M';
                result[i+2][j] = 'A';
                result[i+3][j] = 'S';
                counter++;
            } else if(word == "SAMX") {
                result[i][j] = 'S';
                result[i+1][j] = 'A';
                result[i+2][j] = 'M';
                result[i+3][j] = 'X';
                counter++;
            }
        }
    }
}

void mark_diagonals(const stringVector& original, stringVector& result, int& counter) {
    for(size_t i = 0; i < original.size() - 3; i++) {
        for(size_t j = 0; j < original[i].size() - 3; j++) {
            std::string word;
            word.push_back(original[i][j]);
            word.push_back(original[i+1][j+1]);
            word.push_back(original[i+2][j+2]);
            word.push_back(original[i+3][j+3]);
            if(word == "XMAS") {
                result[i][j] = 'X';
                result[i+1][j+1] = 'M';
                result[i+2][j+2] = 'A';
                result[i+3][j+3] = 'S';
                counter++;
            } else if(word == "SAMX") {
                result[i][j] = 'S';
                result[i+1][j+1] = 'A';
                result[i+2][j+2] = 'M';
                result[i+3][j+3] = 'X';
                counter++;
            }
        }
    }
}

void mark_diagonals_secondary(const stringVector& original, stringVector& result, int& counter) {
    for(size_t i = 0; i < original.size() - 3; i++) {
        for(size_t j = original[i].size(); j >= 3; j--) {
            std::string word;
            word.push_back(original[i][j]);
            word.push_back(original[i+1][j-1]);
            word.push_back(original[i+2][j-2]);
            word.push_back(original[i+3][j-3]);
            if(word == "XMAS") {
                result[i][j] = 'X';
                result[i+1][j-1] = 'M';
                result[i+2][j-2] = 'A';
                result[i+3][j-3] = 'S';
                counter++;
            } else if(word == "SAMX") {
                result[i][j] = 'S';
                result[i+1][j-1] = 'A';
                result[i+2][j-2] = 'M';
                result[i+3][j-3] = 'X';
                counter++;
            }
        }
    }
}