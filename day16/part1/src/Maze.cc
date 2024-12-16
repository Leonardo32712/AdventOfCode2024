#include "../include/Maze.h"

Maze::Maze(std::vector<std::string> map) : MazeMap(map) {}

Maze::~Maze() {}

void Maze::printMaze() {
    for(std::string line : MazeMap) {
        for(char c : line) {
            std::cout << c << " " << std::flush;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}