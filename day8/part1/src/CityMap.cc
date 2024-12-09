#include "../include/CityMap.h"

CityMap::CityMap(stringVector map) {
    this->map = map;
    analyzeMap();
}

CityMap::~CityMap() {}

void CityMap::analyzeMap() {
    for(size_t i = 0; i < map.size(); i++) {
        for(size_t j = 0; j < map[i].size(); j++) {
            char freq = map[i][j];
            if(freq != '.') {
                saveAntenna(freq, intPair(i,j));
            }
        }
    }
}

void CityMap::saveAntenna(const char freq, const intPair pos) {
    if(frequencies.find(freq) == frequencies.end()) {
        frequencies.insert(freq);
        antennas.push_back(Antenna(freq, pos));
    } else {
        for(Antenna& ant : antennas) {
            if(ant.getFrequency() == freq) {
                ant.saveLocation(pos);
            }
        }
    }
}

void CityMap::printCity() {
    system("clear");
    for(std::string line : map) {
    }
}

void CityMap::printCityData() {
    for(Antenna antenna : antennas) {
        antenna.print();
    }
}