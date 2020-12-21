//
// Created by Casper De Smet on 10/12/2020.
//

#include "LaneModel.h"

using namespace std;

namespace turboHiker
{
    LaneModel::LaneModel(const weak_ptr<WorldModel>& worldModel, int index, const list<shared_ptr<HikerModel>>& hikers):
                         worldModel(worldModel), index(index), hikers(hikers)
    {
        cout << "LaneModel " << index << " is getting constructed!" << endl;
    }

    std::string LaneModel::toString()
    {
        stringstream output;
        output << "Lane " << index << " has hikers:" << endl;
        for (const shared_ptr<HikerModel>& hiker: hikers)
            output << "\t" << hiker->toString() << endl;
        return output.str();
    }
}
