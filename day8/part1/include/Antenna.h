#include <vector>
#include <iostream>

typedef std::pair<size_t,size_t> Coordenade;
typedef std::pair<Coordenade,Coordenade> doubleCoordenades;
typedef std::vector<Coordenade> CoordenadeVector;

class Antenna {
    private:
        const char antennaFrecuency;
        CoordenadeVector locations;

    public:
        Antenna(char, Coordenade);
        ~Antenna();

        void saveLocation(const Coordenade);
        size_t getLocationsCount();
        doubleCoordenades getAntinodes(const size_t, const size_t);
        char getFrequency();

        void print();
};
