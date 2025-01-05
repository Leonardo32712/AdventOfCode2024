#pragma once

#include <string>
#include <vector>

namespace Constants {
    inline const std::pair<int,int> NUMERIC_PAD_START_POSITION = {3,2};
    inline const std::vector<std::string> NUMERIC_PAD = {
        "789",
        "456",
        "123",
        "_0A"
    };

    inline const std::pair<int,int> DIRECTIONAL_PAD_START_POSITION = {0,2};
    inline const std::vector<std::string> DIRECTIONAL_PAD = {
        "_^A",
        "<v>"
    };
}
