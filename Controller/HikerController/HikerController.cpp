//
// Created by Casper De Smet on 19/12/2020.
//

#include "HikerController.h"
#include "../World.h"

using namespace std;

namespace turboHiker
{
    // Constructor for hiker controller: the hiker starts living and moving, but the game isn't started, so it doesn't actually move
    HikerController::HikerController(const weak_ptr<World>& world, int index): world(world), hikerIndex(index), living(true),
                                                                               started(false), moving(true), interval(6), laneIndex(index),
                                                                               onTimeOutFor(0), timeOut(3000)
    {
        hikerTask = packaged_task<void()>(bind(&HikerController::live, this));
        hikerFuture = hikerTask.get_future();
    }

    HikerController::~HikerController()
    {
        // If the game hasn't started, the thread hasn't been started either,
        // so we don't have to wait for it to finish
        if (started)
            hikerFuture.wait();
    }

    // Handle an incoming event
    void HikerController::handleEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            // Start the thread and set started to true
            case Event::StartGame:
                thread(move(hikerTask)).detach();
                started = true;
                break;
            // Stop the hiker by setting living to false
            case Event::StopGame:
            case Event::ForceStopGame:
                living = false;
                break;
            // Change the lane index if the hiker is moving
            case Event::MoveLeft:
            case Event::MoveRight:
                if (moving)
                    changeLaneIndex(event->eventType);
                break;
            // Check if the hiker can go faster or slower and change the interval if it can
            case Event::SpeedUp:
                if (interval > 3)
                    interval--;
                break;
            case Event::SpeedDown:
                if (interval <= 8)
                    interval++;
                break;
            // Stop or start the hiker
            case Event::HaltHiker:              stopMoving(event->eventType);   break;
            case Event::LetGoHiker:             startMoving();                  break;
            case Event::CollisionWithHiker:
            case Event::CollisionWithObstacle:  stopMoving(event->eventType);   break;
            default:
                break;
        }
    }

    // Set moving to false and raise an event to do the same in the model
    void HikerController::stopMoving(Event::EventType eventType)
    {
        moving = false;
        world.lock()->handleEvent(make_shared<Event>(Event::StopMoving, hikerIndex));
        if (eventType == Event::CollisionWithHiker || eventType == Event::CollisionWithObstacle)
            world.lock()->handleEvent(make_shared<Event>(Event::Jump, hikerIndex));
    }

    // Set moving to true and raise an event to do the same in the model
    void HikerController::startMoving()
    {
        moving = true;
        world.lock()->handleEvent(make_shared<Event>(Event::StartMoving, hikerIndex));
    }

    void HikerController::changeLaneIndex(Event::EventType eventType)
    {
        switch (eventType)
        {
            // If the hiker wants to go left but is already in the left lane, it can't
            case Event::MoveLeft:
                if (laneIndex > 0)
                    laneIndex--;
                break;
            // If the hiker wants to go right but is already in the right lane, it can't
            case Event::MoveRight:
                if (laneIndex < 3)
                    laneIndex++;
                break;
            default:
                break;
        }
    }
}