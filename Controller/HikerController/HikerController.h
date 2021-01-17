//
// Created by Casper De Smet on 19/12/2020.
//

#ifndef TURBOHIKER_HIKERCONTROLLER_H
#define TURBOHIKER_HIKERCONTROLLER_H

#include <memory>
#include <thread>
#include <future>
#include <queue>
#include <sstream>
#include <iostream>
#include <functional>
#include "../../Event/Event.h"

namespace turboHiker
{
    class World;

    // Base class for all hiker controllers
    class HikerController
    {
    protected:
        int hikerIndex;
        int laneIndex;

        // Flag to check if the hiker is still living
        bool living;
        // Interval between steps
        int interval;
        // Flag to check if the game has started yet
        bool started;

        // Flag to check if the hiker is moving
        bool moving;

        // Time out duration
        int timeOut;
        // How long we have been on time out for
        int onTimeOutFor;

        std::weak_ptr<World> world;

        // Members to handle separate thread
        std::packaged_task<void()> hikerTask;
        std::future<void> hikerFuture;

        // Function all derived classes need to implement
        virtual void live() = 0;

    public:
        HikerController(const std::weak_ptr<World>& world, int index);
        virtual ~HikerController();

        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;

        // Set moving to false and true respectively
        void stopMoving(Event::EventType eventType);
        void startMoving();

        // Change the lane index based on the event being raised
        void changeLaneIndex(Event::EventType eventType);
    };
}


#endif //TURBOHIKER_HIKERCONTROLLER_H
