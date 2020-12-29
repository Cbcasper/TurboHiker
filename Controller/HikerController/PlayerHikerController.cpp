//
// Created by Casper De Smet on 20/12/2020.
//

#include "PlayerHikerController.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    PlayerHikerController::PlayerHikerController(const std::weak_ptr<World>& world, int index): HikerController(world, index), moving(false)
    {

    }

    void PlayerHikerController::live()
    {
        stringstream message;
        while (living)
        {
            message << "HikerController " << hikerIndex;
            if (!world.expired())
                world.lock()->handleEvent(make_shared<Event>(Event::MoveForward, hikerIndex));
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }

    void PlayerHikerController::handleEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::StartCountDown:
                break;
            case Event::CountDown:
                break;
            case Event::StartGame:
                break;
            case Event::StopGame:
                break;
            case Event::ForceStopGame:
                break;
            case Event::MoveLeft:
            case Event::MoveRight:
                changeLaneIndex(event->eventType);
                break;
            case Event::MoveForward:
                break;
            case Event::SpeedUp:
                if (interval > 1)
                    interval--;
                break;
            case Event::SpeedDown:
                if (interval <= 10)
                    interval++;
                break;
            case Event::StateUpdated:
                break;
        }
    }

//    void PlayerHikerController::handleEvent(const shared_ptr<Event>& event)
//    {
//        switch (event->eventType)
//        {
//            case Event::HikerModelEvent:
//                break;
//            case Event::HikerViewEvent:
//            {
//                shared_ptr<HikerViewEvent> hikerViewEvent = dynamic_pointer_cast<HikerViewEvent>(event);
//                cout << "PlayerHikerController received a hikerViewEvent.\n";
//                switch (hikerViewEvent->hikerEventType)
//                {
//                    case HikerEvent::Move:
//                        changeLaneIndex(hikerViewEvent->direction);
//                        world.lock()->raiseControllerEvent(make_shared<HikerControllerEvent>(hikerIndex, HikerEvent::Move, hikerViewEvent->direction, laneIndex));
//                        break;
//                    case HikerEvent::SpeedUp:
//                        if (interval > 1)
//                            interval--;
//                        break;
//                    case HikerEvent::SpeedDown:
//                        if (interval <= 10)
//                            interval++;
//                        break;
//                    default:
//                        break;
//                }
//            }
//                break;
//            default:
//                break;
//        }
//    }

    PlayerHikerController::~PlayerHikerController()
    {
        cout << "PlayerHikerController " << hikerIndex << " is getting destructed." << endl;
    }

    void PlayerHikerController::changeLaneIndex(Event::EventType eventType)
    {
        switch (eventType)
        {
            case Event::MoveLeft:
                if (laneIndex > 0)
                    laneIndex--;
                break;
            case Event::MoveRight:
                if (laneIndex < 3)
                    laneIndex++;
                break;
            default:
                break;
        }
    }
}