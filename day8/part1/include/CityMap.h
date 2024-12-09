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
        CoordenadeVector antinodesCoordenades;

        void analyzeMap();
        void saveAntenna(const char, const Coordenade);
        bool checkAntinode(const Coordenade);
        bool antinodeRegistered(const Coordenade);
        bool outOfMap(const Coordenade);
    public:
        CityMap(stringVector);
        ~CityMap();

        int markAntinodes();
        void printCity();
        void printCityData();
};
