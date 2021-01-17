//
// Created by Casper De Smet on 11/12/2020.
//

#include "WorldView.h"
#include "ObstacleView.h"

using namespace std;

namespace turboHiker
{
    WorldView::WorldView(const weak_ptr<World>& world, double screenX, double screenY): world(world), screenX(screenX), screenY(screenY)
    {}

//    void WorldView::raiseEvent(const shared_ptr<ViewEvent>& viewEvent)
//    {
//        stringstream message;
//        message << "WorldView says 'A viewEvent was raised: " << viewEvent->what() << "'" << endl;
//        cout << message.str();
//        world.lock()->raiseViewEvent(viewEvent);
//    }


    const std::shared_ptr<HikerView>& WorldView::getHiker(int index)
    {
        return hikers[index];
    }

    int WorldView::getScreenX()
    {
        return screenX;
    }

    int WorldView::getScreenY()
    {
        return screenY;
    }

    void WorldView::changeLane(int hikerIndex, Event::EventType eventType)
    {
        shared_ptr<HikerView> hiker = hikers[hikerIndex];
        int laneIndex = hiker->getLaneIndex();
        shared_ptr<LaneView> oldLane = lanes[laneIndex];
        eventType == Event::MoveLeft ? --laneIndex : ++laneIndex;
        shared_ptr<LaneView> newLane = lanes[laneIndex];

        oldLane->removeHiker(hiker);
        newLane->addHiker(hiker);
        hiker->setCurrentLane(newLane);
    }

    const std::shared_ptr<ObstacleView>& WorldView::getObstacle(int obstacleIndex)
    {
        return obstacles[obstacleIndex];
    }

    void WorldView::addHiker(const shared_ptr<AbstractHiker>& hiker)
    {
        hikers.emplace_back(dynamic_pointer_cast<HikerView>(hiker));
    }

    void WorldView::addObstacle(const shared_ptr<AbstractObstacle>& obstacle)
    {
        obstacles.emplace_back(dynamic_pointer_cast<ObstacleView>(obstacle));
    }

    void WorldView::addLane(const shared_ptr<AbstractLane>& lane)
    {
        lanes.emplace_back(dynamic_pointer_cast<LaneView>(lane));
    }

    shared_ptr<AbstractLane> WorldView::getAbstractLane(int laneIndex)
    {
        return lanes[laneIndex];
    }

    const std::shared_ptr<LaneView>& WorldView::getLane(int index)
    {
        return lanes[index];
    }
}