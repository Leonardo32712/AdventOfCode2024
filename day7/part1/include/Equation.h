#include <string>

#include "../include/OpBitScheme.h"

typedef std::vector<int> intVector;

class Equation {
    private:
        const size_t amountOfOperations;
        OpBitScheme operationScheme;
        long independentTerm;
        intVector operands;

    public:
        Equation(long, intVector);
        ~Equation();

        bool canBeSolved();
        long getIndependentTerm();
        void print(long);
};