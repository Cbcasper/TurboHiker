//
// Created by Casper De Smet on 20/12/2020.
//

#include "PlayerHikerController.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    // The player hiker is not halted at the start
    PlayerHikerController::PlayerHikerController(const std::weak_ptr<World>& world, int index): HikerController(world, index), halted(false)
    {

    }

    void PlayerHikerController::live()
    {
        while (living)
        {
            // Raise event to move the hiker forward
            if (moving)
                world.lock()->handleEvent(make_shared<Event>(Event::MoveForward, hikerIndex));
            // If the hiker is halted, it is not on time out so it doesn't need to handle the time out logic
            else if (!halted)
            {
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
            }
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }

    void PlayerHikerController::handleEvent(const shared_ptr<Event>& event)
    {
        HikerController::handleEvent(event);
        switch (event->eventType)
        {
            // Set halted accordingly
            case Event::HaltHiker: halted = true;    break;
            case Event::LetGoHiker: halted = false;  break;
            default:                                 break;
        }
    }
}