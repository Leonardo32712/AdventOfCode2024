#include "../include/Antenna.h"

Antenna::Antenna(char frecuency, intPair location) : antennaFrecuency(frecuency), locations({}) {
    saveLocation(location);
}

Antenna::~Antenna() {}

void Antenna::saveLocation(const intPair location) {
    locations.push_back(location);
}

size_t Antenna::getLocationsCount() {
    return locations.size();
}

intPair Antenna::getLocation(const size_t position) {
    if(position < 0 || position >= locations.size()) {
        throw std::runtime_error("Antenna position out of range.");
    }

    return locations[position];
}

char Antenna::getFrequency() {
    return antennaFrecuency;
}

void Antenna::print() {
    std::cout << "Frequency [" << antennaFrecuency << " " << locations.size() << "]: " << std::flush;
    for(intPair location : locations) {
        std::cout << "(" << location.first << "," << location.second << ") " << std::flush;
    }
    std::cout << std::endl;
}