//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_LANEVIEW_H
#define TURBOHIKER_LANEVIEW_H

#include <iostream>
#include <future>
#include <thread>
#include <sstream>
#include <memory>
#include <list>
#include "../TurboHikerFactory/AbstractLane.h"

namespace turboHiker
{
    class WorldView;
    class HikerView;
    class ObstacleView;

    // Interface
    class LaneView: public AbstractLane, public std::enable_shared_from_this<LaneView>
    {
    protected:
        std::weak_ptr<WorldView> worldView;
        std::list<std::shared_ptr<HikerView>> hikers;
        std::list<std::shared_ptr<ObstacleView>> obstacles;

        int index;

    public:
        LaneView(const std::weak_ptr<WorldView>& world, int laneIndex, const std::shared_ptr<turboHiker::HikerView>& hiker);

        // Implementation of abstract function of interface AbstractLane
        void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) override;

        // Utility functions that a lane view will have, regardless of the implementation
        int getIndex() const;

        void removeHiker(const std::shared_ptr<HikerView>& hiker);
        void addHiker(const std::shared_ptr<HikerView>& hiker);

        void addObstacle(const std::shared_ptr<ObstacleView>& obstacle);
    };
}


#endif //TURBOHIKER_LANEVIEW_H
