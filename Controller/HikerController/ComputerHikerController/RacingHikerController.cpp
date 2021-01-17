//
// Created by Casper De Smet on 20/12/2020.
//

#include "RacingHikerController.h"
#include "../../World.h"

using namespace std;

namespace turboHiker
{
    RacingHikerController::RacingHikerController(const weak_ptr<World>& world, int index): ComputerHikerController(world, index, -5)
    {
        interval = Random::getInstance().randomInt(4, 8);
    }

    void RacingHikerController::live()
    {
        while (living)
        {
            // Raise event to move the hiker forward
            if (moving)
            {
                beAlive();
                world.lock()->handleEvent(make_shared<Event>(Event::MoveForward, hikerIndex));
            }
            else
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

    void RacingHikerController::handleEvent(const shared_ptr<Event>& event)
    {
        HikerController::handleEvent(event);
    }
}