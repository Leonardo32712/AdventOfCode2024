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
                saveAntenna(freq, Coordenade(i,j));
            }
        }
    }
}

void CityMap::saveAntenna(const char freq, const Coordenade pos) {
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

int CityMap::markAndCountAntinodes() {
    int antinodesCounter = 0;

    for (Antenna& ant : antennas) {
        antinodesCounter += processAntinodePairs(ant);
        antinodesCounter += processIndividualLocations(ant);
    }

    return antinodesCounter;
}

int CityMap::processAntinodePairs(Antenna& ant) {
    int counter = 0;

    for (size_t i = 0; i < ant.getLocationsCount() - 1; i++) {
        for (size_t j = i + 1; j < ant.getLocationsCount(); j++) {
            counter += findAndMarkAntinodes(ant, i, j);
        }
    }

    return counter;
}

int CityMap::processIndividualLocations(Antenna& ant) {
    int counter = 0;

    if (ant.getLocationsCount() > 1) {
        for (size_t a = 0; a < ant.getLocationsCount(); a++) {
            const Coordenade& location = ant.getLocation(a);
            if (checkAntinode(location)) {
                antinodesCoordenades.push_back(location);
                counter++;
            }
        }
    }

    return counter;
}

int CityMap::findAndMarkAntinodes(Antenna& ant, size_t i, size_t j) {
    int counter = 0;
    int resonantHarmonic = 1;
    doubleCoordenades antinodes;

    do {
        antinodes = ant.getAntinodes(i, j, resonantHarmonic);

        if (!outOfMap(antinodes.first) && checkAntinode(antinodes.first)) {
            antinodesCoordenades.push_back(antinodes.first);
            counter++;
        }
        if (!outOfMap(antinodes.second) && checkAntinode(antinodes.second)) {
            antinodesCoordenades.push_back(antinodes.second);
            counter++;
        }

        resonantHarmonic++;
    } while (!outOfMap(antinodes.first) || !outOfMap(antinodes.second));

    return counter;
}

bool CityMap::checkAntinode(const Coordenade pos) {
    if (!outOfMap(pos) && !antinodeRegistered(pos)) {
        if(map[pos.first][pos.second] == '.') {
            map[pos.first][pos.second] = '#';
        }
        return true;
    } else {
        return false;
    }
}

bool CityMap::antinodeRegistered(const Coordenade pos) {
    for(Coordenade coord : antinodesCoordenades) {
        if(coord.first == pos.first && coord.second == pos.second) {
            return true;
        }
    }
    return false;
}

bool CityMap::outOfMap(const Coordenade pos) {
    if (pos.first < 0 || pos.first >= map.size() || pos.second < 0 || pos.second >= map[0].size()) {
        return true;
    } else {
        return false;
    }
}

void CityMap::printCity() {
    for(std::string line : map) {
        std::cout << line << std::endl;
    }
}

void CityMap::printCityData() {
    for(Antenna antenna : antennas) {
        antenna.print();
    }

    std::cout << "Antinodes: " << std::endl;
    for(Coordenade coord : antinodesCoordenades) {
        std::cout << "(" << coord.first << "," << coord.second << ") " << std::flush;
    }
    std::cout << std::endl << std::endl;
}