//
// Created by Casper De Smet on 10/12/2020.
//

#include "WorldModel.h"
#include "../Controller/World.h"

using namespace std;

namespace turboHiker
{
    WorldModel::WorldModel(const weak_ptr<World>& world): world(world)
    {
        cout << "This worldModel is getting constructed." << endl;
    }

    void WorldModel::raiseEvent(const shared_ptr<ModelEvent>& event)
    {
        world.lock()->raiseModelEvent(event);
    }

    const std::shared_ptr<HikerModel>& WorldModel::getHiker(int hikerIndex)
    {
        return hikers[hikerIndex];
    }

    std::shared_ptr<HikerModel> WorldModel::constructHiker(int hikerIndex, const weak_ptr<WorldModel>& worldModel)
    {
        shared_ptr<HikerModel> hiker = make_shared<HikerModel>(worldModel, hikerIndex);
        hikers.emplace_back(hiker);
        return hiker;
    }

    void WorldModel::constructLane(int laneIndex, const weak_ptr<WorldModel>& worldModel, const list<shared_ptr<HikerModel>>& hikerList)
    {
        shared_ptr<LaneModel> lane = make_shared<LaneModel>(worldModel, laneIndex, hikerList);
        lanes.emplace_back(lane);
        for (const shared_ptr<HikerModel>& hiker: hikerList)
            hiker->setCurrentLane(lane);
    }

    std::string WorldModel::toString()
    {
        stringstream output;
        output << "This is the world model:" << endl
               << "Lanes: " << endl;
        for (const shared_ptr<LaneModel>& lane: lanes)
            output << "\t" << lane->toString() << endl;
        output << "Hikers: " << endl;
        for (const shared_ptr<HikerModel>& hiker: hikers)
            output << "\t" << hiker->toString() << endl;
        return output.str();
    }
}