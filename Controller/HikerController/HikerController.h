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
#include "../../Event/Event.h"
#include "../../Event/GameEvent.h"

namespace turboHiker
{
    class World;

    class HikerController
    {
    protected:
        int index;
        bool living;
        int interval;

        std::weak_ptr<World> world;

        std::packaged_task<void()> hikerTask;
        std::future<void> hikerFuture;

        virtual void live() = 0;

    public:
        HikerController(const std::weak_ptr<World>& world, int index);
        virtual ~HikerController();

        virtual void raiseEvent(const std::shared_ptr<Event>& event) = 0;
        void raiseGameEvent(const std::shared_ptr<GameEvent>& event);

        void timedMessages();
    };
}


#endif //TURBOHIKER_HIKERCONTROLLER_H
