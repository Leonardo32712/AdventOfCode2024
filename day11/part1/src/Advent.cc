#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    StoneArrange sa (fr.readStoneArrange());

    sa.printStones();
    return 0;
}

