#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<long> longVector;

enum OpCode {
    ADV = 0,
    BXL = 1,
    BST = 2,
    JNZ = 3,
    BXC = 4,
    OUT = 5,
    BDV = 6,
    CDV = 7
};

class Computer {
    private:
        longVector registers;
        const longVector program;
        longVector output;
        int IP;
        bool jumped;

        void operate(int, long);
        long getComboOP(long);
    public:
        Computer(longVector, longVector);
        ~Computer();

        longVector getProgramResult();
        void printPC();
        void printRegisters();
        void printProgram();
        void printOutput();
};