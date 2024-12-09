#include "../include/Antenna.h"

Antenna::Antenna(char frecuency, Coordenade location) : antennaFrecuency(frecuency), locations({}) {
    saveLocation(location);
}

Antenna::~Antenna() {}

void Antenna::saveLocation(const Coordenade location) {
    locations.push_back(location);
}

size_t Antenna::getLocationsCount() {
    return locations.size();
}

Coordenade Antenna::getLocation(size_t position) {
    return locations[position];
}

doubleCoordenades Antenna::getAntinodes(const size_t i, const size_t j, int resonance) {
    if (i >= locations.size() || j >= locations.size()) {
        throw std::runtime_error("Antenna position out of range.");
    }

    const int factor1 = resonance + 1;
    const int factor2 = resonance;

    const Coordenade& locI = locations[i];
    const Coordenade& locJ = locations[j];

    Coordenade firstAntinode(
        locI.first * factor1 - locJ.first * factor2,
        locI.second * factor1 - locJ.second * factor2
    );
    Coordenade secondAntinode(
        locJ.first * factor1 - locI.first * factor2,
        locJ.second * factor1 - locI.second * factor2
    );

    return doubleCoordenades(firstAntinode, secondAntinode);
}


char Antenna::getFrequency() {
    return antennaFrecuency;
}

void Antenna::print() {
    std::cout << "Frequency [" << antennaFrecuency << " " << locations.size() << "]: " << std::flush;
    for(Coordenade location : locations) {
        std::cout << "(" << location.first << "," << location.second << ") " << std::flush;
    }
    std::cout << std::endl;
}