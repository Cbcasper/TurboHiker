//
// Created by Casper De Smet on 16/01/2021.
//

#ifndef TURBOHIKER_HIKERSCORE_H
#define TURBOHIKER_HIKERSCORE_H

#include <chrono>

namespace turboHiker
{
    class HikerScore
    {
    private:
        // The time a hiker took to finish
        std::chrono::milliseconds gameLength;

    public:
        HikerScore();

        void setGameLength(const std::chrono::milliseconds& givenGameLength);
        const std::chrono::milliseconds& getGameLength() const;
    };
}


#endif //TURBOHIKER_HIKERSCORE_H
