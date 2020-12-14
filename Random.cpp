//
// Created by Casper De Smet on 06/12/2020.
//

#include "Random.h"

using namespace std;

namespace turboHiker
{
    Random::Random()
    {
        random_device randomDevice;
        engine = default_random_engine(randomDevice());
    }

    Random Random::getInstance()
    {
        static Random random = Random();
        return random;
    }

    int Random::randomInt(int a, int b)
    {
        random_device randomDevice;
        engine.seed(randomDevice());
        uniform_int_distribution<int> intDistribution(a, b);
        return intDistribution(engine);
    }

    double Random::randomDouble(double a, double b)
    {
        random_device randomDevice;
        engine.seed(randomDevice());
        uniform_real_distribution<double> doubleDistribution(a, b);
        return doubleDistribution(engine);
    }
}