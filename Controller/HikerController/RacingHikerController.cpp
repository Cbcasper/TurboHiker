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
        stringstream message;
        while (living)
        {
            message << "HikerController " << hikerIndex;
            if (!world.expired())
                world.lock()->handleEvent(make_shared<Event>(Event::MoveForward, hikerIndex));
            this_thread::sleep_for(chrono::milliseconds(interval));
        }
    }

    void RacingHikerController::handleEvent(const shared_ptr<Event>& event)
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

    RacingHikerController::~RacingHikerController()
    {
        cout << "RacingHikerController " << hikerIndex << " is getting destructed." << endl;
    }
}