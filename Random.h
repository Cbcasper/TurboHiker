//
// Created by Casper De Smet on 06/12/2020.
//

#ifndef TURBOHIKER_RANDOM_H
#define TURBOHIKER_RANDOM_H

#include <memory>
#include <random>

namespace turboHiker
{
    class Random
    {
    private:
        std::default_random_engine engine;

        Random();

    public:
        static Random getInstance();
        int randomInt(int a, int b);
        double randomDouble(double a, double b);
    };
}


#endif //TURBOHIKER_RANDOM_H
