//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_LANEMODEL_H
#define TURBOHIKER_LANEMODEL_H

#include <iostream>

using namespace std;

namespace turboHiker
{
    class WorldModel;

    class LaneModel
    {
    private:
        int index;
        shared_ptr<WorldModel> world;

    public:
        LaneModel(const shared_ptr<WorldModel>& world, int index);
    };
}


#endif //TURBOHIKER_LANEMODEL_H
