//
// Created by Casper De Smet on 17/01/2021.
//

#include "ModelFactory.h"

using namespace std;

namespace turboHiker
{
    shared_ptr<AbstractHiker> ModelFactory::createHiker(int hikerIndex, World::HikerType hikerType, const weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y)
    {
        // Make a hiker
        shared_ptr<HikerModel> hiker;
        switch (hikerType)
        {
            // Find the right type and assign it to the hiker
            case World::PlayerHiker:
                hiker = make_shared<PlayerHikerModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()), hikerIndex);
                dynamic_pointer_cast<WorldModel>(worldComponent.lock())->setPlayerHiker(hiker);
                break;
            case World::RacingHiker: hiker = make_shared<RacingHikerModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()), hikerIndex);               break;
            case World::StandingHiker: hiker = make_shared<StandingHikerModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()), hikerIndex, x, y);     break;
            case World::AdversaryHiker: hiker = make_shared<AdversaryHikerModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()), hikerIndex, x, y);   break;
        }
        // Store the hiker and return it
        worldComponent.lock()->addHiker(hiker);
        return hiker;
    }

    shared_ptr<AbstractObstacle> ModelFactory::createObstacle(int laneIndex, const weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y)
    {
        // Make an obstacle
        shared_ptr<ObstacleModel> obstacle = make_shared<ObstacleModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()),
                                                                        dynamic_pointer_cast<LaneModel>(worldComponent.lock()->getAbstractLane(laneIndex)), x, y);
        // Store it
        worldComponent.lock()->addObstacle(obstacle);
        // Add it to the correct lane
        worldComponent.lock()->getAbstractLane(laneIndex)->addObstacle(obstacle);
        return obstacle;
    }

    shared_ptr<AbstractLane> ModelFactory::createLane(int laneIndex, const weak_ptr<AbstractWorldComponent>& worldComponent, const shared_ptr<AbstractHiker>& hiker)
    {
        // Make a lane
        shared_ptr<LaneModel> lane = make_shared<LaneModel>(dynamic_pointer_cast<WorldModel>(worldComponent.lock()), laneIndex, dynamic_pointer_cast<HikerModel>(hiker));
        // Store it
        worldComponent.lock()->addLane(lane);
        // And initialize the lane of the hiker
        dynamic_pointer_cast<HikerModel>(hiker)->initializeCurrentLane(lane);
        return lane;
    }

    shared_ptr<AbstractWorldComponent> ModelFactory::createWorldComponent(const weak_ptr<World>& world, double width, double height)
    {
        return make_shared<WorldModel>(world, width, height);
    }
}