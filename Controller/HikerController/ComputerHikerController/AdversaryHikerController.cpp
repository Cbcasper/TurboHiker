//
// Created by Casper De Smet on 16/01/2021.
//

#include "AdversaryHikerController.h"
#include "../../World.h"

using namespace std;

namespace turboHiker
{
    // The adversary hiker overrides the vertical offset, because it has to check in another direction for obstacles
    AdversaryHikerController::AdversaryHikerController(const weak_ptr<World>& world, int index): ComputerHikerController(world, index, 5)
    {

    }

    void AdversaryHikerController::live()
    {
        while (living)
        {
            // Raise event to move the hiker towards the player
            if (moving)
            {
                beAlive();
                world.lock()->handleEvent(make_shared<Event>(Event::MoveBackward, hikerIndex));
            }
            else
                // Be on time out
                if (onTimeOutFor < timeOut)
                    onTimeOutFor += interval;
                else
                {
                    // Reset time out and start moving again
                    onTimeOutFor = 0;
                    moving = true;
                    world.lock()->handleEvent(make_shared<Event>(Event::StartMoving, hikerIndex));
                }
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }

    void AdversaryHikerController::handleEvent(const shared_ptr<Event>& event)
    {
        HikerController::handleEvent(event);
    }
}