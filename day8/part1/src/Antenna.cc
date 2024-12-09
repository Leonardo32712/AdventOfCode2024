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

doubleCoordenades Antenna::getAntinodes(const size_t i, const size_t j) {
    if(i < 0 || i >= locations.size() || j < 0 || j >= locations.size()) {
        throw std::runtime_error("Antenna position out of range.");
    }
    
    Coordenade firstAntinode(
        locations[i].first*2 - locations[j].first, 
        locations[i].second*2 - locations[j].second);
    Coordenade secondAntinode(
        locations[j].first*2 - locations[i].first, 
        locations[j].second*2 - locations[i].second);

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