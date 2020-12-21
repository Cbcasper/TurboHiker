//
// Created by Casper De Smet on 20/12/2020.
//

#include "PlayerHikerController.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    PlayerHikerController::PlayerHikerController(const std::weak_ptr<World>& world, int index): HikerController(world, index), moving(false)
    {}

    void PlayerHikerController::live()
    {
        while (living)
        {
            if (moving)
            {
                this_thread::sleep_for(chrono::milliseconds(interval));
                stringstream message;
                message << "HikerController " << index;
                world.lock()->raiseControllerEvent(make_shared<HikerControllerEvent>(index, HikerEvent::UpdateState, message.str()));
            }
        }
    }

    void PlayerHikerController::raiseEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::HikerModelEvent:
                break;
            case Event::HikerViewEvent:
                cout << "PlayerHikerController received a hikerViewEvent.\n";
                switch (dynamic_pointer_cast<HikerViewEvent>(event)->hikerEventType)
                {
                    case HikerEvent::StartMoving:
                        moving = true;
                        break;
                    case HikerEvent::StopMoving:
                        moving = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    PlayerHikerController::~PlayerHikerController()
    {
        cout << "PlayerHikerController " << index << " is getting destructed." << endl;
    }
}