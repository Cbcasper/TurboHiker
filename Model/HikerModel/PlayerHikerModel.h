//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERMODEL_H
#define TURBOHIKER_PLAYERHIKERMODEL_H

#include "HikerModel.h"

namespace turboHiker
{
    class PlayerHikerModel: public HikerModel
    {
    public:
        PlayerHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex);
    };
}

#endif //TURBOHIKER_PLAYERHIKERMODEL_H
