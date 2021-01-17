//
// Created by Casper De Smet on 15/01/2021.
//

#include "StandingHikerModel.h"

namespace turboHiker
{
    StandingHikerModel::StandingHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex, double newX, double newY):
            HikerModel(worldModel, hikerIndex)
    {
        x = newX;
        y = newY;
        moving = false;
    }
}