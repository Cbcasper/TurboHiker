//
// Created by Casper De Smet on 10/12/2020.
//

#include "LaneModel.h"

namespace turboHiker
{
    LaneModel::LaneModel(const shared_ptr<WorldModel>& world, int index): world(world), index(index)
    {
        cout << "Lane model " << index << " is getting constructed!" << endl;
    }
}
