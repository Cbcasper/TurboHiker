//
// Created by Casper De Smet on 06/12/2020.
//

#include "Random.h"

namespace turboHiker
{
    Random::Random()
    {
        random_device randomDevice;
        generator = default_random_engine(randomDevice());
    }

    shared_ptr<Random> Random::getInstance()
    {
        static shared_ptr<Random> random = shared_ptr<Random>();
        return random;
    }

    int Random::randomInt(int a, int b)
    {
        intDistribution = uniform_int_distribution(a, b);
        return intDistribution(generator);
    }

    double Random::randomDouble(double a, double b)
    {
        doubleDistribution = uniform_real_distribution(a, b);
        return doubleDistribution(generator);
    }
}