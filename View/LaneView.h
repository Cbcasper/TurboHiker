//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_LANEVIEW_H
#define TURBOHIKER_LANEVIEW_H

#include <iostream>
#include <future>
#include <thread>
#include <sstream>

namespace turboHiker
{
    class WorldView;

    class LaneView
    {
    private:
        int index;
        std::shared_ptr<WorldView> world;
        std::packaged_task<void()> laneTask;
        std::future<void> laneFuture;

        void startLiving() const;

    public:
        LaneView(const std::shared_ptr<WorldView>& world, int index);
        void raiseEvent();
        void start();
        void wait();
    };
}


#endif //TURBOHIKER_LANEVIEW_H
