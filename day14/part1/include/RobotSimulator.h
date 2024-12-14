#include "Robot.h"

const int WIDE = 101;
const int TALL = 103;

class RobotSimulator {
    private:
        std::vector<Robot> robots;

        bool outOfBounds(size_t, size_t);
    public:
        RobotSimulator(std::vector<Robot>);
        ~RobotSimulator();

        void printRobots();
};