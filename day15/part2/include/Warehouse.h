#include "Robot.h"

class Warehouse {
    private:
        std::vector<std::string> wareHouseMap;
        Robot robot;

        intPair findRobot();
        bool checkMove(intPair, Direction);
        bool checkMoveBox(intPair, Direction, bool);

        bool checkFreeMoveBox(intPair, Direction);
        bool checkVerticalMoveBox(intPair, intPair, Direction, bool);
        bool checkLeftMoveBox(intPair, intPair, Direction, bool);
        bool checkRightMoveBox(intPair, intPair, Direction, bool);
        bool checkMultiVerticalMoveBox(intPair, intPair, Direction, bool);

        intPair getNextStep(intPair, Direction);
        void saveBoxMove(intPair, intPair, Direction);
        bool outOfBounds(intPair);
    public:
        Warehouse(std::vector<std::string>, std::vector<Direction>);
        ~Warehouse();

        void simulateMove();
        void doubleWide();
        long getSumGPS();
        void printWarehouse();
};