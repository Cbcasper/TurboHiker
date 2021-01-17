//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_STANDINGHIKERMODEL_H
#define TURBOHIKER_STANDINGHIKERMODEL_H

#include "HikerModel.h"

namespace turboHiker
{
    class StandingHikerModel: public HikerModel
    {
    public:
        // A standing hiker doesn't have a set initial location, so this can be passed through
        StandingHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex, double newX, double newY);
    };
}


#endif //TURBOHIKER_STANDINGHIKERMODEL_H
