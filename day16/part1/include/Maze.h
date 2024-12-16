#include <iostream>
#include <vector>

class Maze {
    private:
        std::vector<std::string> MazeMap;

    public:
        Maze(std::vector<std::string>);
        ~Maze();

        void printMaze();
};