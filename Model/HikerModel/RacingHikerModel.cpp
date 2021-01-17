//
// Created by Casper De Smet on 21/12/2020.
//

#include "RacingHikerModel.h"

using namespace std;

namespace turboHiker
{
    RacingHikerModel::RacingHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex) :
            HikerModel(worldModel, hikerIndex)
    {}
}