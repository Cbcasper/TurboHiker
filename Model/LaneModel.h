//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_LANEMODEL_H
#define TURBOHIKER_LANEMODEL_H

#include <iostream>

namespace turboHiker
{
    class WorldModel;

    class LaneModel
    {
    private:
        int index;
        std::shared_ptr<WorldModel> worldModel;

    public:
        LaneModel(const std::shared_ptr<WorldModel>& worldModel, int index);
    };
}


#endif //TURBOHIKER_LANEMODEL_H
