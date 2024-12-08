#include <iostream>
#include <bitset>
#include <vector>

class OpScheme {
private:
    unsigned long operationSchemeNumber;
    size_t numberOfOperations;
    int base;

public:
    OpScheme(size_t, int);
    ~OpScheme();

    void add(int);
    bool initialState();
    std::string toString();
};

