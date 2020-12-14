//
// Created by Casper De Smet on 10/12/2020.
//

#include "WorldModel.h"
#include "../Controller/World.h"

using namespace std;

namespace turboHiker
{
    WorldModel::WorldModel(const shared_ptr<World>& world): world(world), inWait(true)
    {
        cout << "This worldModel is getting constructed." << endl;
        shared_ptr<WorldModel> model = make_shared<WorldModel>(*this);
        for (int i = 0; i < 4; ++i)
        {
            lanes.emplace_back(make_shared<LaneModel>(model, i));
            hikers.emplace_back(make_shared<HikerModel>(model, i));
        }
    }

    void WorldModel::start()
    {
        this_thread::sleep_for(chrono::milliseconds(3000));
        inWait = false;
    }

    void WorldModel::wait()
    {
        for (const shared_ptr<HikerModel>& hiker: hikers)
            hiker->wait();
    }

    void WorldModel::raiseEvent(const shared_ptr<ModelEvent>& event)
    {
        world->raiseModelEvent(event);
    }

    bool WorldModel::isInWait() const
    {
        return inWait;
    }
}