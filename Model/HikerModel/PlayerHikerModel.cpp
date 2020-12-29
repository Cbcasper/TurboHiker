//
// Created by Casper De Smet on 21/12/2020.
//

#include "PlayerHikerModel.h"

namespace turboHiker
{
    PlayerHikerModel::PlayerHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex) :
            HikerModel(worldModel, hikerIndex)
    {}
}