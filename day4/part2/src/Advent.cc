#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::vector<std::string> stringVector;

void read_file(std::string);
stringVector get_XMAS_ocurrences(const stringVector&);
void print_result(const stringVector&, const int&);
void mark_ocurrences(const stringVector&, stringVector&, int&);
bool check_corners(const stringVector&, int, int);

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

    mark_ocurrences(original, result, ocurrences_counter);
    
    print_result(result, ocurrences_counter);

    return result;
}

void print_result(const stringVector& result, const int& counter) {
    for(size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
    std::cout << "The result is " << counter << ".";
}

void mark_ocurrences(const stringVector& original, stringVector& result, int& counter) {
    for(size_t i = 1; i < original.size() - 1; i++) {
        for(size_t j = 1; j < original[i].size() - 1; j++) {
            if(original[i][j] == 'A') {
                if(check_corners(original, i, j)) {
                    result[i][j] = original[i][j];
                    result[i-1][j-1] = original[i-1][j-1];
                    result[i-1][j+1] = original[i-1][j+1];
                    result[i+1][j-1] = original[i+1][j-1];
                    result[i+1][j+1] = original[i+1][j+1];
                    counter++;
                }
            }
        }
    }
}

bool check_corners(const stringVector& original, int i, int j) {
    std::string corner_chars;
    corner_chars.push_back(original[i-1][j-1]);
    corner_chars.push_back(original[i-1][j+1]);
    corner_chars.push_back(original[i+1][j-1]);
    corner_chars.push_back(original[i+1][j+1]);

    if(corner_chars == "MMSS" || corner_chars == "MSMS" || corner_chars == "SMSM" || corner_chars == "SSMM") {
        return true;
    } else {
        return false;
    }
}