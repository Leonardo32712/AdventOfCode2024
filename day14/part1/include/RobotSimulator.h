#include "Robot.h"

class RobotSimulator {
    private:
        std::vector<Robot> robots;

        std::vector<int> getQuadrants();
        long calculateSafetyFactor(std::vector<int>);
    public:
        RobotSimulator(std::vector<Robot>);
        ~RobotSimulator();

        long getSafetyFactor(int);
        void printRobots();
};