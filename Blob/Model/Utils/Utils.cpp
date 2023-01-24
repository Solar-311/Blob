/* ########## INCLUDE ########## */
/* FILES */
#include "Utils.h"

int Utils::generateRandomNumber(int lo, int hi)
{
    static std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<double> dist(lo, hi);
    return dist(rng);
}

float Utils::generateRandomFNumber()
{
    float lo = 20, hi = 30;
    float fNumber = lo + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (hi - lo)));

    return fNumber;
}
