#include <vector>
#include <iostream>
#include <cmath>

typedef std::vector<std::pair<int,int>> intPairVector;
typedef std::vector<std::vector<int>> intMatrix;
typedef std::vector<int> intVector;

class safetyManual {
    private:
        intPairVector rules;
        intMatrix updatePages;

        bool checkPage(const intVector);
        bool checkRules(const int,const int);
    public:
        safetyManual();
        safetyManual(intPairVector, intMatrix);
        ~safetyManual();

        void emplaceRule(int,int);
        void pushUpdatePages(intVector);
        int sumCorrectPages();
        
        void printManual();
};
