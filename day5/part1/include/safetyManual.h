#include <vector>
#include <iostream>

typedef std::vector<std::pair<int,int>> intPairVector;
typedef std::vector<std::vector<int>> intMatrix;

class safetyManual {
    private:
        intPairVector rules;
        intMatrix updatePages;
    public:
        safetyManual();
        safetyManual(intPairVector, intMatrix);
        ~safetyManual();

        void emplaceRule(int,int);
        void pushUpdatePages(std::vector<int>);

        void printManual();
};
