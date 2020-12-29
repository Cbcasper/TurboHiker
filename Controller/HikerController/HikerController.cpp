//
// Created by Casper De Smet on 19/12/2020.
//

#include "HikerController.h"
#include "../../Event/GameEvent.h"
#include "../../Event/ControllerEvent/HikerControllerEvent.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    HikerController::HikerController(const weak_ptr<World>& world, int index): world(world), hikerIndex(index), living(true), started(false), interval(5), laneIndex(index)
    {
        hikerTask = packaged_task<void()>(bind(&HikerController::live, this));
        hikerFuture = hikerTask.get_future();
    }

    HikerController::~HikerController()
    {
        cout << "Waiting for hikerFuture..." << endl;
        if (started)
            hikerFuture.wait();
        cout << "HikerFuture has finished." << endl;
    }

//    void HikerController::raiseGameEvent(const shared_ptr<GameEvent>& event)
//    {
//        switch (event->gameEventType)
//        {
//            case GameEvent::Start:
//                thread(move(hikerTask)).detach();
//                started = true;
//                break;
//            case GameEvent::ForcedStop:
//            case GameEvent::Stop:
//                {
//                    message << "HikerController " << hikerIndex << " stops living." << endl;
//                    cout << message.str();
//                    living = false;
//                }
//                break;
//            default:
//                break;
//        }
//    }

    void HikerController::handleEvent(const shared_ptr<Event>& event)
    {
        stringstream message;
        switch (event->eventType)
        {
            case Event::StartCountDown:
                break;
            case Event::CountDown:
                break;
            case Event::StartGame:
                thread(move(hikerTask)).detach();
                started = true;
                break;
            case Event::StopGame:
            case Event::ForceStopGame:
                message << "HikerController " << hikerIndex << " stops living." << endl;
                cout << message.str();
                living = false;
                break;
            case Event::MoveLeft:
                break;
            case Event::MoveRight:
                break;
            case Event::MoveForward:
                break;
            case Event::SpeedUp:
                break;
            case Event::SpeedDown:
                break;
            case Event::StateUpdated:
                break;
        }
    }
}