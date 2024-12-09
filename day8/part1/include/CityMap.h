#include <vector>
#include <iostream>
#include <set>

#include "Antenna.h"

typedef std::vector<std::string> stringVector;
typedef std::vector<Antenna> antennaVector;

class CityMap {
    private:
        stringVector map;
        antennaVector antennas;
        std::set<char> frequencies;

        void analyzeMap();
        void saveAntenna(const char, const intPair);
    public:
        CityMap(stringVector);
        ~CityMap();

        void printCity();
        void printCityData();
};
