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
        int processAntinodePairs(Antenna&);
        int processIndividualLocations(Antenna&);
        int findAndMarkAntinodes(Antenna&, size_t, size_t);
        bool checkAntinode(const Coordenade);
        bool antinodeRegistered(const Coordenade);
        bool outOfMap(const Coordenade);
    public:
        CityMap(stringVector);
        ~CityMap();

        int markAndCountAntinodes();
        void printCity();
        void printCityData();
};
