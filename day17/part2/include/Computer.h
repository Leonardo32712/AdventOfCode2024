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

        long dfs(int, long);
        void operate(int, long);
        long getComboOP(long);
        void clearPC(long);
        void printRegisters();
        void printProgram();
    public:
        Computer(longVector, longVector);
        ~Computer();

        long findInitialRegisterA();
        longVector execute();
        void printPC();
        void printOutput();
};