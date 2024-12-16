#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Maze maze (fr.readMaze());

    maze.printMaze();
    //std::cout << wh.getSumGPS() << std::endl;

    return 0;
}

