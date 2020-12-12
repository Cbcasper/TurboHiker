//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_WORLDMODEL_H
#define TURBOHIKER_WORLDMODEL_H

#include <vector>
#include <memory>
#include "LaneModel.h"

using namespace std;

namespace turboHiker
{
    class Controller;

    class WorldModel
    {
    private:
        shared_ptr<Controller> controller;
        vector<shared_ptr<LaneModel>> lanes;

    public:
        WorldModel(const shared_ptr<Controller>& controller);
    };
}

#endif //TURBOHIKER_WORLDMODEL_H
