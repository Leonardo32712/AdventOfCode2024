#include "Robot.h"

class Warehouse {
    private:
        std::vector<std::string> wareHouseMap;
        Robot robot;

    public:
        Warehouse(std::vector<std::string>, std::vector<Direction>);
        ~Warehouse();

        long getSumGPS();
        void printWarehouse();
};