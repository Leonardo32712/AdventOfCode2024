#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {
    fileReader fr(argv[1]);
    Maze maze (fr.readMaze());
    long totalCount = maze.getBestPathsTilesCount();

    maze.printMaze();
    std::cout << "Total Count: " << totalCount << std::endl;
    return 0;
}

