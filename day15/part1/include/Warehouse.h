#include "Robot.h"

class Warehouse {
    private:
        std::vector<std::string> wareHouseMap;
        Robot robot;

        intPair findRobot();
        void simulateMove();
        bool checkMove(intPair, Direction);
        bool moveBox(intPair, Direction);
        intPair getNextStep(intPair, Direction);
        bool outOfBounds(intPair);
    public:
        Warehouse(std::vector<std::string>, std::vector<Direction>);
        ~Warehouse();

        long getSumGPS();
        void printWarehouse();
};