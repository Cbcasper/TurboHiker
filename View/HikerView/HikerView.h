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
#include "../../Event/ModelEvent/ModelEvent.h"
#include "../../Event/ViewEvent/ViewEvent.h"
#include "../../Event/ViewEvent/HikerViewEvent.h"
#include "../LaneView.h"

namespace turboHiker
{
    class WorldView;

    class HikerView
    {
    protected:
        int hikerIndex;
        std::weak_ptr<WorldView> worldView;
        std::weak_ptr<LaneView> currentLane;

    public:
        HikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
        virtual ~HikerView() = default;

        void setCurrentLane(const std::weak_ptr<LaneView>& givenCurrentLane);

        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;
        void raiseEvent();

        int getIndex() const;
    };
}


#endif //TURBOHIKER_HIKERVIEW_H
