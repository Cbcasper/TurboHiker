//
// Created by Casper De Smet on 20/12/2020.
//

#include "RacingHikerController.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    RacingHikerController::RacingHikerController(const weak_ptr<World>& world, int index): HikerController(world, index)
    {}

    void RacingHikerController::live()
    {
        while (living)
        {
            stringstream message;
            message << "HikerController " << index;
            world.lock()->raiseControllerEvent(make_shared<HikerControllerEvent>(index, HikerEvent::UpdateState, message.str()));
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }

    void RacingHikerController::raiseEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::HikerModelEvent:
                break;
            case Event::HikerViewEvent:
                break;
            default:
                break;
        }
    }

    RacingHikerController::~RacingHikerController()
    {
        cout << "RacingHikerController " << index << " is getting destructed." << endl;
    }
}