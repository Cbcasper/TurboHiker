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
    HikerController::HikerController(const weak_ptr<World>& world, int index): world(world), index(index), living(true), interval(10)
    {
        hikerTask = packaged_task<void()>(bind(&HikerController::live, this));
        hikerFuture = hikerTask.get_future();
    }

    HikerController::~HikerController()
    {
        cout << "Waiting for hikerFuture..." << endl;
        hikerFuture.wait();
        cout << "HikerFuture has finished." << endl;
    }

    void HikerController::timedMessages()
    {
        int timeToLive = 5000;
        int hasLivedFor = 0;
        int interval = (index + 1) * 250;

        stringstream intervalMessage;
        intervalMessage << "HikerController " << index << " has an interval of " << interval << endl;
        cout << intervalMessage.str();

        while (hasLivedFor < timeToLive)
        {
            this_thread::sleep_for(chrono::milliseconds(interval));
            hasLivedFor += interval;
            stringstream message;
            message << "HikerController " << index << " at " << hasLivedFor;
            cout << message.str() << endl;
            world.lock()->raiseControllerEvent(make_shared<HikerControllerEvent>(index, HikerEvent::UpdateState, message.str()));
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void HikerController::raiseGameEvent(const shared_ptr<GameEvent>& event)
    {
        switch (event->gameEventType)
        {
            case GameEvent::Start:
                thread(move(hikerTask)).detach();
                break;
            case GameEvent::ForcedStop:
            case GameEvent::Stop:
                {
                    stringstream message;
                    message << "HikerController " << index << " stops living." << endl;
                    cout << message.str();
                    living = false;
                }
                break;
        }
    }
}