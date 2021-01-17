//
// Created by Casper De Smet on 16/01/2021.
//

#ifndef TURBOHIKER_COMPUTERHIKERCONTROLLER_H
#define TURBOHIKER_COMPUTERHIKERCONTROLLER_H

#include "../HikerController.h"
#include "../../../Model/HikerModel/Hitbox.h"

namespace turboHiker
{
    class WorldModel;

    // Base class for AdversaryHiker and RacingHiker
    class ComputerHikerController: public HikerController
    {
    protected:
        // Distance to check for obstacles ahead
        double verticalOffset;

        std::weak_ptr<WorldModel> worldModel;

        // To be executed every time alive
        void beAlive();

    public:
        ComputerHikerController(const std::weak_ptr<World>& world, int index, double verticalOffset);

        // Check if there will be a collision if the hitbox would be in a certain position
        bool obstacleAhead(const std::shared_ptr<Hitbox>& hitbox);
        // Calculate what the best action to the coming collision is
        std::shared_ptr<Event> moveAside(const std::shared_ptr<Hitbox>& hitbox);
    };
}


#endif //TURBOHIKER_COMPUTERHIKERCONTROLLER_H
