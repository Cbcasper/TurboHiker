//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEW_H
#define TURBOHIKER_HIKERVIEW_H

#include <memory>
#include <iostream>
#include <sstream>
#include <future>
#include <thread>
#include "../LaneView.h"
#include "../../Event/Event.h"
#include "../../TurboHikerFactory/AbstractHiker.h"

namespace turboHiker
{
    class WorldView;

    // Base class for hiker interfaces. Contains abstract functions that will be called by the world
    class HikerView: public AbstractHiker
    {
    protected:
        int hikerIndex;

        // Link to parent objects
        std::weak_ptr<WorldView> worldView;
        std::weak_ptr<LaneView> currentLane;

    public:
        HikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
        virtual ~HikerView() = default;

        void setCurrentLane(const std::weak_ptr<LaneView>& givenCurrentLane);

        // Abstract function for handling event
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;

        int getIndex() const;
        int getLaneIndex() const;

        // Abstract function to get the hitbox size
        virtual std::pair<float, float> getHitboxSize() const = 0;
    };
}


#endif //TURBOHIKER_HIKERVIEW_H
