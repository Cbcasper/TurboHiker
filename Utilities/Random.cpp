//
// Created by Casper De Smet on 06/12/2020.
//

#include "Random.h"

using namespace std;

namespace turboHiker
{
    Random& Random::getInstance()
    {
        // Make a random instance and return it
        static Random random = Random();
        return random;
    }

    int Random::randomInt(int a, int b)
    {
        // Make a random device to seed a random engine to power a uniform distribution
        random_device randomDevice;
        default_random_engine engine(randomDevice());
        uniform_int_distribution<int> intDistribution(a, b);
        return intDistribution(engine);
    }

    double Random::randomDouble(double a, double b)
    {
        // Make a random device to seed a random engine to power a uniform distribution
        random_device randomDevice;
        default_random_engine engine(randomDevice());
        uniform_real_distribution<double> doubleDistribution(a, b);
        return doubleDistribution(engine);
    }
}