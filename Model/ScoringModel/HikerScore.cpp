//
// Created by Casper De Smet on 16/01/2021.
//

#include "HikerScore.h"

using namespace std;

namespace turboHiker
{
    HikerScore::HikerScore(): gameLength(chrono::milliseconds(0))
    {}


    void HikerScore::setGameLength(const chrono::milliseconds& givenGameLength)
    {
        gameLength = givenGameLength;
    }

    const chrono::milliseconds& HikerScore::getGameLength() const
    {
        return gameLength;
    }
}