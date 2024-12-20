#include <iostream>
#include <vector>

typedef std::vector<int> intVector;


class Computer {
    private:
        intVector registers;
        const intVector program;

    public:
        Computer(intVector, intVector);
        ~Computer();

        //intVector getProgramResult();
        void printPC();
        void printRegisters();
        void printProgram();
};