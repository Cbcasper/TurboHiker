//
// Created by Casper De Smet on 10/12/2020.
//

#include "LaneModel.h"

using namespace std;

namespace turboHiker
{
    LaneModel::LaneModel(const shared_ptr<WorldModel>& worldModel, int index): worldModel(worldModel), index(index)
    {
        cout << "LaneModel " << index << " is getting constructed!" << endl;
    }
}
