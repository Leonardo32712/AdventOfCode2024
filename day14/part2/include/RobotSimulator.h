#include "Robot.h"

class RobotSimulator {
    private:
        const std::vector<Robot> originalRobots;
        std::vector<Robot> robots;

        long getConections();
        std::vector<int> getQuadrants();
        long calculateSafetyFactor(std::vector<int>);
        void resetRobots();
    public:
        RobotSimulator(std::vector<Robot>);
        ~RobotSimulator();

        long getBestConnection(int);
        void printRobots(int);
};