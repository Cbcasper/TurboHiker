//
// Created by Casper De Smet on 17/01/2021.
//

#include "ViewFactory.h"

using namespace std;

namespace turboHiker
{
    std::shared_ptr<AbstractHiker> ViewFactory::createHiker(int hikerIndex, World::HikerType hikerType, const weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y)
    {
        // Construct a hiker
        shared_ptr<HikerView> hiker;
        switch (hikerType)
        {
            // Find the right type and assign it
            case turboHiker::World::PlayerHiker:
                hiker = getPlayerHiker(dynamic_pointer_cast<WorldView>(worldComponent.lock()), hikerIndex);
                dynamic_pointer_cast<WorldView>(worldComponent.lock())->setPlayerHiker(hiker);
                break;
            case turboHiker::World::RacingHiker: hiker = getRacingHiker(dynamic_pointer_cast<WorldView>(worldComponent.lock()), hikerIndex);                break;
            case turboHiker::World::StandingHiker: hiker = getStandingHiker(dynamic_pointer_cast<WorldView>(worldComponent.lock()), hikerIndex, x, y);      break;
            case turboHiker::World::AdversaryHiker: hiker = getAdversaryHiker(dynamic_pointer_cast<WorldView>(worldComponent.lock()), hikerIndex, x, y);    break;
            default:
                break;
        }
        // Store it and return it
        worldComponent.lock()->addHiker(hiker);
        return hiker;
    }

    shared_ptr<AbstractObstacle> ViewFactory::createObstacle(int laneIndex, const weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y)
    {
        // Make an obstacle
        shared_ptr<ObstacleView> obstacle = getObstacle(dynamic_pointer_cast<WorldView>(worldComponent.lock()),
                                                        dynamic_pointer_cast<LaneView>(
                                                                worldComponent.lock()->getAbstractLane(laneIndex)), x, y);
        // Store it
        worldComponent.lock()->addObstacle(obstacle);
        // Add it to the correct lane
        worldComponent.lock()->getAbstractLane(laneIndex)->addObstacle(obstacle);
        return obstacle;
    }

    shared_ptr<AbstractLane> ViewFactory::createLane(int laneIndex, const weak_ptr<AbstractWorldComponent>& worldComponent, const shared_ptr<AbstractHiker>& hiker)
    {
        // Make a lane
        shared_ptr<LaneView> lane = getLane(dynamic_pointer_cast<WorldView>(worldComponent.lock()), laneIndex,
                                                        dynamic_pointer_cast<HikerView>(hiker));
        // Store it
        worldComponent.lock()->addLane(lane);
        // And initialize the lane of the hiker
        dynamic_pointer_cast<HikerView>(hiker)->setCurrentLane(lane);
        return lane;
    }

    shared_ptr<AbstractWorldComponent> ViewFactory::createWorldComponent(const weak_ptr<World>& world, double width, double height)
    {
        return getWorldView(world, width, height);
    }
}
