//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_GAMEMODEL_H
#define TURBOHIKER_GAMEMODEL_H

#include <memory>
#include <vector>
#include "LaneModel.h"

namespace turboHiker
{
    class GameModel
    {
    private:
        std::vector<std::shared_ptr<LaneModel>> lanes;
    };
}


#endif //TURBOHIKER_GAMEMODEL_H
