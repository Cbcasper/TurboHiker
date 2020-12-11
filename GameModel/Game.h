//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <memory>
#include <vector>
#include "Lane.h"

using namespace std;

namespace turboHiker
{
    class Game
    {
    private:
        vector<shared_ptr<Lane>> lanes;
    };
}


#endif //TURBOHIKER_GAME_H
