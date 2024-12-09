#include <vector>
#include <iostream>

typedef std::pair<int,int> intPair;
typedef std::vector<intPair> intPairVector;

class Antenna {
    private:
        const char antennaFrecuency;
        intPairVector locations;

    public:
        Antenna(char, intPair);
        ~Antenna();

        void saveLocation(const intPair);
        size_t getLocationsCount();
        intPair getLocation(const size_t);
        char getFrequency();

        void print();
};
