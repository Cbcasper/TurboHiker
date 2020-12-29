//
// Created by Casper De Smet on 10/12/2020.
//

#include "WorldModel.h"
#include "../Controller/World.h"

using namespace std;

namespace turboHiker
{
    WorldModel::WorldModel(const weak_ptr<World>& world, double worldX, double worldY): world(world), worldX(worldX), worldY(worldY)
    {
        cout << "This worldModel is getting constructed." << endl;
    }

    void WorldModel::raiseEvent(const shared_ptr<Event>& event)
    {
        world.lock()->handleEvent(event);
    }

    const std::shared_ptr<HikerModel>& WorldModel::getHiker(int hikerIndex)
    {
        return hikers[hikerIndex];
    }

    std::shared_ptr<HikerModel> WorldModel::constructHiker(int hikerIndex, World::HikerType hikerType, const weak_ptr<WorldModel>& worldModel)
    {
        shared_ptr<HikerModel> hiker;
        switch (hikerType)
        {
            case World::PlayerHiker:
                hiker = make_shared<PlayerHikerModel>(worldModel, hikerIndex);
                break;
            case World::RacingHiker:
                hiker = make_shared<RacingHikerModel>(worldModel, hikerIndex);
                break;
        }
        hikers.emplace_back(hiker);
        return hiker;
    }

    void WorldModel::constructLane(int laneIndex, const weak_ptr<WorldModel>& worldModel, const list<shared_ptr<HikerModel>>& hikerList)
    {
        shared_ptr<LaneModel> lane = make_shared<LaneModel>(worldModel, laneIndex, hikerList);
        lanes.emplace_back(lane);
        for (const shared_ptr<HikerModel>& hiker: hikerList)
            hiker->initializeCurrentLane(lane);
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

    double WorldModel::getWorldX() const
    {
        return worldX;
    }

    double WorldModel::getWorldY() const
    {
        return worldY;
    }

    void WorldModel::changeLane(int hikerIndex, Event::EventType eventType)
    {
        shared_ptr<HikerModel> hiker = hikers[hikerIndex];
        int laneIndex = hiker->getLaneIndex();
        shared_ptr<LaneModel> oldLane = lanes[laneIndex];
        int newLaneIndex = eventType == Event::MoveLeft ? --laneIndex : ++laneIndex;
        shared_ptr<LaneModel> newLane = lanes[newLaneIndex];

        oldLane->removeHiker(hiker);
        newLane->addHikers(hiker);
        hiker->setCurrentLane(newLane);
    }
}