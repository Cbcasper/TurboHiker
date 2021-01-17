//
// Created by Casper De Smet on 15/01/2021.
//

#include "AdversaryHikerModel.h"

using namespace std;

namespace turboHiker
{
    AdversaryHikerModel::AdversaryHikerModel(const weak_ptr<WorldModel>& worldModel, int hikerIndex, double newX, double newY):
            HikerModel(worldModel, hikerIndex)
    {
        x = newX;
        y = newY;
    }
}