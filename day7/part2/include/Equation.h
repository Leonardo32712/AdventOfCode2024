#include <string>

#include "../include/OpScheme.h"

typedef std::vector<int> intVector;

class Equation {
    private:
        const size_t amountOfOperations;
        OpScheme operationScheme;
        long independentTerm;
        intVector operands;
        long operate();

    public:
        Equation(long, intVector);
        ~Equation();

        bool canBeSolved();
        long getIndependentTerm();
        void print(long);
};