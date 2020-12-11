//
// Created by Casper De Smet on 06/12/2020.
//

#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <memory>
#include <random>

using namespace std;

namespace turboHiker
{
    class Random
    {
    private:
        default_random_engine generator;
        uniform_int_distribution<int> intDistribution;
        uniform_real_distribution<double> doubleDistribution;

        Random();

    public:
        static shared_ptr<Random> getInstance();
        int randomInt(int a, int b);
        double randomDouble(double a, double b);
    };
}


#endif //TURBOHIKER_RANDOM_H
