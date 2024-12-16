#include <sstream>
#include <fstream>
#include <algorithm>

#include "Maze.h"

class fileReader {
private:
    std::ifstream file;

public:
    fileReader(std::string);
    ~fileReader();

    Maze readMaze();
};