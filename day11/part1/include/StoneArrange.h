#include <vector>
#include <iostream>
#include <string>

typedef std::vector<int> intVector;

class StoneArrange {
    private:
        intVector stones;
        int timesBlinked;

        void blink();
    public:
        StoneArrange(intVector);
        ~StoneArrange();

        size_t getStonesCount();
        void printStones();
};
