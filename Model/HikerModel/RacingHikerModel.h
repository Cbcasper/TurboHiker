//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_RACINGHIKERMODEL_H
#define TURBOHIKER_RACINGHIKERMODEL_H

#include "HikerModel.h"

namespace turboHiker
{
    class RacingHikerModel: public HikerModel
    {
    public:
        RacingHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex);
    };
}


#endif //TURBOHIKER_RACINGHIKERMODEL_H
