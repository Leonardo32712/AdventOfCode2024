#include "../include/FileReader.h"

int main(int argc, char const *argv[]) {

    fileReader fr(argv[1]);
    Garden g (fr.readgardenMap());

    std::cout << "Total price: " << g.totalPrice() << std::endl;
    return 0;
}

