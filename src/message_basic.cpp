#include "message_basic.h"


namespace jc
{
    std::string make_daytime_string()
    {
        std::time_t now = std::time(nullptr);
        return std::ctime(&now);
    }

    float generate_random_number()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<float> dist(1.0, 10.0);
        return dist(mt);
    }
}
