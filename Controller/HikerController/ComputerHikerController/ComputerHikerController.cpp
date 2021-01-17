//
// Created by Casper De Smet on 16/01/2021.
//

#include "ComputerHikerController.h"
#include "../../World.h"
#include "../../../Model/WorldModel.h"


using namespace std;

namespace turboHiker
{
    ComputerHikerController::ComputerHikerController(const weak_ptr<World>& world, int index, double verticalOffset):
                HikerController(world, index), verticalOffset(verticalOffset), worldModel(world.lock()->getModel())
    {}

    void ComputerHikerController::beAlive()
    {
        // Fetch the hitbox from the model
        shared_ptr<Hitbox> hitbox = worldModel.lock()->getHiker(hikerIndex)->getHitbox();
        shared_ptr<Event> event;
        // Check for collision and react
        if (obstacleAhead(hitbox))
            event = moveAside(hitbox);

        // Raise the event, if there is one
        if (event)
            world.lock()->handleEvent(event);
    }


    bool ComputerHikerController::obstacleAhead(const shared_ptr<Hitbox>& hitbox)
    {
        // Move the hitbox to a future location vertically
        hitbox->moveVertically(verticalOffset);

        // Ask the worldModel for collisions
        if (!worldModel.lock()->checkForCollisions(hitbox, hikerIndex, WorldModel::Obstacles).empty())
            return true;
        return false;
    }

    shared_ptr<Event> ComputerHikerController::moveAside(const shared_ptr<Hitbox>& hitbox)
    {
        // If the hiker is at an edge, always move in the opposite direction
        if (world.lock()->atEdge(hikerIndex, Event::MoveLeft))
            return make_shared<Event>(Event::MoveRight, hikerIndex);
        else if (world.lock()->atEdge(hikerIndex, Event::MoveRight))
            return make_shared<Event>(Event::MoveLeft, hikerIndex);

        // Check if there is an obstacle to the right
        hitbox->moveHorizontally(50);
        if (worldModel.lock()->checkForCollisions(hitbox, hikerIndex, WorldModel::Obstacles).empty())
            // If there isn't one, go to the right
            return make_shared<Event>(Event::MoveLeft, hikerIndex);

        // Check to the left
        hitbox->moveHorizontally(-100);
        if (worldModel.lock()->checkForCollisions(hitbox, hikerIndex, WorldModel::Obstacles).empty())
            return make_shared<Event>(Event::MoveRight, hikerIndex);

        return nullptr;
    }
}