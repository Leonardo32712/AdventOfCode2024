#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    StoneArrange sa (fr.readStoneArrange());

    sa.printStones();

    std::cout << "After 25 blinks there are " << sa.blink(25) << " stones." << std::endl;
    return 0;
}

