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
    protected:
        std::vector<std::shared_ptr<LaneView>> lanes;
        std::vector<std::shared_ptr<HikerView>> hikers;

        std::weak_ptr<World> world;

    public:
        WorldView();
        void setWorld(const std::weak_ptr<World>& givenWorld);
        void raiseEvent(const std::shared_ptr<ViewEvent>& viewEvent);

        const std::shared_ptr<LaneView>& getLane(int index);
        const std::shared_ptr<HikerView>& getHiker(int index);

        virtual std::shared_ptr<HikerView> constructHiker(int hikerIndex, const std::weak_ptr<WorldView>& worldView) = 0;
        virtual void constructLane(int laneIndex, const std::weak_ptr<WorldView>& worldView, const std::list<std::shared_ptr<HikerView>>& hikers) = 0;

        virtual void render() = 0;
    };
}


#endif //TURBOHIKER_WORLDVIEW_H
