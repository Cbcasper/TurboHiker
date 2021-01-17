//
// Created by Casper De Smet on 10/12/2020.
//

#include "WorldModel.h"
#include "../Controller/World.h"
#include "ObstacleModel.h"

using namespace std;

namespace turboHiker
{
    WorldModel::WorldModel(const weak_ptr<World>& world, double worldX, double worldY): world(world), worldX(worldX), worldY(worldY)
    {}

    void WorldModel::raiseEvent(const shared_ptr<Event>& event)
    {
        world.lock()->handleEvent(event);
    }

    const std::shared_ptr<HikerModel>& WorldModel::getHiker(int hikerIndex)
    {
        return hikers[hikerIndex];
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
        // Get the hiker, old lane and new lane
        shared_ptr<HikerModel> hiker = hikers[hikerIndex];
        int laneIndex = hiker->getLaneIndex();
        shared_ptr<LaneModel> oldLane = lanes[laneIndex];
        eventType == Event::MoveLeft ? --laneIndex : ++laneIndex;
        shared_ptr<LaneModel> newLane = lanes[laneIndex];

        // Transfer the hiker to the new lane
        oldLane->removeHiker(hiker);
        newLane->addHiker(hiker);
        hiker->setCurrentLane(newLane);
    }

    const std::shared_ptr<ObstacleModel>& WorldModel::getObstacle(int obstacleIndex)
    {
        return obstacles[obstacleIndex];
    }

    void WorldModel::handleEvent(const std::shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::Tick:
            {
                // Update the state of the player first and then all other hikers
                world.lock()->handleEvent(make_shared<Event>(Event::HikerStateUpdated, playerHiker));
                for (const shared_ptr<HikerModel>& hiker: hikers)
                    if (hiker != playerHiker)
                        world.lock()->handleEvent(make_shared<Event>(Event::HikerStateUpdated, hiker));
                // Update the state of all obstacles
                for (const shared_ptr<ObstacleModel>& obstacle: obstacles)
                    world.lock()->handleEvent(make_shared<Event>(Event::ObstacleStateUpdated, obstacle));
            }
                break;
            case Event::StopGame:
                playerHiker->handleEvent(event);
                break;
            case Event::GamePrepared:
                scoring->setPlayerName(event->getPlayerName());
                break;
            default:
                break;
        }
    }

    bool WorldModel::availableLocation(double x, double y)
    {
        // Place it a bit off the edge
        if (x < 10 || x > worldX - 10 || y < 10 || y > worldY - 10)
            return false;
        // Make sure the location is more than 100 units away from all other objects
        for (const shared_ptr<ObstacleModel>& obstacle: obstacles)
            if (abs(obstacle->getX() - x) < obstacle->getHitboxWidth() && abs(obstacle->getY() - y) < obstacle->getHitboxHeight())
                return false;
        for (const shared_ptr<HikerModel>& hiker: hikers)
            if (abs(hiker->getX() - x) < hiker->getHitboxWidth() && abs(hiker->getY() - y) < hiker->getHitboxHeight())
                return false;
        return true;
    }

    void WorldModel::checkForCollisions()
    {
        // Collects all events that need to be raised
        vector<shared_ptr<Event>> events;
        // Go over all hikers and check if they collide with anything
        for (const shared_ptr<HikerModel>& hiker: hikers)
            for (const shared_ptr<Event>& event: checkForCollisions(hiker))
                events.emplace_back(event);

        // Raise all events
        for (const shared_ptr<Event>& event: events)
            world.lock()->handleEvent(event);
    }

    const std::shared_ptr<LaneModel>& WorldModel::getLane(int index) const
    {
        return lanes[index];
    }

    vector<shared_ptr<Event>> WorldModel::checkForCollisions(const std::shared_ptr<HikerModel>& hiker)
    {
        // A hiker that is not moving can't have a new undetected collision
        if (!hiker->isMoving()) return {};

        // Collect all events
        vector<shared_ptr<Event>> events;
        // Check all other hikers
        for (const shared_ptr<HikerModel>& otherHiker: hikers)
            if (hiker->collidesWith(otherHiker))
                events.emplace_back(make_shared<Event>(Event::CollisionWithHiker, hiker->getIndex(), otherHiker->getIndex()));
        // Check all obstacles that are not broken
        for (const shared_ptr<ObstacleModel>& obstacle: obstacles)
            if (!obstacle->isBroken() && hiker->collidesWith(obstacle))
                events.emplace_back(make_shared<Event>(Event::CollisionWithObstacle, hiker->getIndex(), obstacle->getIndex()));
        return events;
    }

    vector<shared_ptr<Event>> WorldModel::checkForCollisions(const shared_ptr<Hitbox>& hitbox, int hikerIndex, CheckFor checkFor)
    {
        vector<shared_ptr<Event>> events;
        // Determine if we need to check hikers
        if (checkFor == Hikers || checkFor == Both)
            for (const shared_ptr<HikerModel>& otherHiker: hikers)
                if (hitbox->collidesWith(otherHiker->getHitbox()))
                    events.emplace_back(make_shared<Event>(Event::CollisionWithHiker, hikerIndex, otherHiker->getIndex()));
        // Determine if we need to check obstacles
        if (checkFor == Obstacles || checkFor == Both)
            for (const shared_ptr<ObstacleModel>& obstacle: obstacles)
                if (!obstacle->isBroken() && hitbox->collidesWith(obstacle->getHitbox()))
                    events.emplace_back(make_shared<Event>(Event::CollisionWithObstacle, hikerIndex, obstacle->getIndex()));
        return events;
    }

    bool WorldModel::checkIfFinished()
    {
        if (playerHiker->finished())
            scoring->writeScore();
        return playerHiker->finished();
    }

    void WorldModel::addHiker(const shared_ptr<AbstractHiker>& hiker)
    {
        hikers.emplace_back(dynamic_pointer_cast<HikerModel>(hiker));
    }

    void WorldModel::addObstacle(const shared_ptr<AbstractObstacle>& obstacle)
    {
        obstacles.emplace_back(dynamic_pointer_cast<ObstacleModel>(obstacle));
    }

    void WorldModel::addLane(const shared_ptr<AbstractLane>& lane)
    {
        lanes.emplace_back(dynamic_pointer_cast<LaneModel>(lane));
    }

    shared_ptr<AbstractLane> WorldModel::getAbstractLane(int laneIndex)
    {
        return lanes[laneIndex];
    }

    void WorldModel::setPlayerHiker(const shared_ptr<HikerModel>& hiker)
    {
        playerHiker = dynamic_pointer_cast<PlayerHikerModel>(hiker);
    }

    vector<tuple<chrono::milliseconds, string, string>> WorldModel::constructScoring()
    {
        scoring = make_shared<ScoringModel>();
        playerHiker->setScoring(scoring);
        return scoring->readScore();
    }
}