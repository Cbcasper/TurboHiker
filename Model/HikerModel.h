//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERMODEL_H
#define TURBOHIKER_HIKERMODEL_H

#include <memory>
#include <future>
#include <thread>
#include <iostream>
#include "../Event/ModelEvent/HikerModelEvent.h"
#include "../Event/ViewEvent/ViewEvent.h"

namespace turboHiker
{
    class WorldModel;
    class LaneModel;

    class HikerModel: public std::enable_shared_from_this<HikerModel>
    {
    private:
        int hikerIndex;

        double x;
        double y;

        std::weak_ptr<WorldModel> worldModel;
        std::weak_ptr<LaneModel> currentLane;

    public:
        HikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex);

        void setCurrentLane(const std::weak_ptr<LaneModel>& givenCurrentLane);

        void receiveEvent(const std::shared_ptr<Event>& event);

        std::string toString() const;

        double getX() const;
        double getY() const;

        int getIndex() const;
    };
}


#endif //TURBOHIKER_HIKERMODEL_H
