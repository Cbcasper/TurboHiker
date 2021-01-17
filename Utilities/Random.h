//
// Created by Casper De Smet on 06/12/2020.
//

#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <memory>
#include <random>

namespace turboHiker
{
    // Singleton class for random number generation
    class Random
    {
    private:
        Random() = default;

    public:
        static Random& getInstance();

        // Get a random int or double from a up to and including b
        int randomInt(int a, int b);
        double randomDouble(double a, double b);
    };
}


#endif //TURBOHIKER_RANDOM_H
