//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEW_H
#define TURBOHIKER_WORLDVIEW_H

#include <vector>
#include <memory>
#include <iostream>
#include "LaneView.h"
#include "HikerView/HikerView.h"
#include "../Event/Event.h"
#include "../Event/ViewEvent/ViewEvent.h"
#include "../Controller/World.h"
#include "GameView.h"

namespace turboHiker
{
    class WorldView
    {
    protected:
        int screenX;
        int screenY;

        std::vector<std::shared_ptr<LaneView>> lanes;
        std::vector<std::shared_ptr<HikerView>> hikers;
        std::shared_ptr<GameView> game;

        std::weak_ptr<World> world;

    public:
        WorldView(int screenX, int screenY);

        void setWorld(const std::weak_ptr<World>& givenWorld);
//        void raiseEvent(const std::shared_ptr<ViewEvent>& viewEvent);

        const std::shared_ptr<LaneView>& getLane(int index);
        const std::shared_ptr<HikerView>& getHiker(int index);

        virtual std::shared_ptr<HikerView> constructHiker(int hikerIndex, World::HikerType hikerType, const std::weak_ptr<WorldView>& worldView) = 0;
        virtual void constructLane(int laneIndex, const std::weak_ptr<WorldView>& worldView, const std::list<std::shared_ptr<HikerView>>& hikers) = 0;
        virtual void constructGame() = 0;

        virtual void render() = 0;

//        virtual void receiveGameEvent(const std::shared_ptr<GameEvent>& event) = 0;
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;

        virtual int getScreenX();
        virtual int getScreenY();

        virtual void changeLane(int hikerIndex, Event::EventType eventType) = 0;
    };
}


#endif //TURBOHIKER_WORLDVIEW_H
