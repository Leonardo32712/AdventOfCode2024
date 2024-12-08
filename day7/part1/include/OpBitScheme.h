#include <iostream>
#include <bitset>
#include <vector>

const int BIT_SIZE = 64;

class OpBitScheme {
private:
    unsigned int number;
    size_t size;

public:
    OpBitScheme(size_t);
    ~OpBitScheme();

    void add(int);
    void setBit(int);
    unsigned int getBit(int);
    bool initialState();
    std::string toString();
};

