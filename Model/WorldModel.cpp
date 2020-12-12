//
// Created by Casper De Smet on 10/12/2020.
//

#include "WorldModel.h"

namespace turboHiker
{
    WorldModel::WorldModel(const shared_ptr<Controller>& controller): controller(controller)
    {
        cout << "This world model is getting constructed." << endl;
        shared_ptr<WorldModel> model = make_shared<WorldModel>(*this);
        for (int i = 0; i < 4; ++i)
            lanes.emplace_back(make_shared<LaneModel>(model, i));
    }
}