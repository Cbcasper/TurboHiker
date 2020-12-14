//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEW_H
#define TURBOHIKER_WORLDVIEW_H

#include <vector>
#include <memory>
#include <iostream>
#include "LaneView.h"
#include "HikerView.h"
#include "../Event/Event.h"
#include "../Event/ViewEvent/ViewEvent.h"

namespace turboHiker
{
    class World;

    class WorldView
    {
    private:
        std::shared_ptr<World> world;
        std::vector<std::shared_ptr<LaneView>> lanes;
        std::vector<std::shared_ptr<HikerView>> hikers;

    public:
        WorldView();
        void setWorld(const std::shared_ptr<World>& controller);
        void raiseEvent(const std::shared_ptr<ViewEvent>& viewEvent);

        const std::shared_ptr<LaneView>& getLane(int index);
        const std::shared_ptr<HikerView>& getHiker(int index);

        void start();
        void wait();
    };
}


#endif //TURBOHIKER_WORLDVIEW_H
