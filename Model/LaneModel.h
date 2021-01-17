//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_LANEMODEL_H
#define TURBOHIKER_LANEMODEL_H

#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include "HikerModel/HikerModel.h"
#include "../TurboHikerFactory/AbstractLane.h"

namespace turboHiker
{
    class WorldModel;
    class ObstacleModel;

    class LaneModel: public AbstractLane, public std::enable_shared_from_this<LaneModel>
    {
    private:
        int index;

        std::weak_ptr<WorldModel> worldModel;
        // A list of hikers, that can go between lanes
        std::list<std::shared_ptr<HikerModel>> hikers;
        std::list<std::shared_ptr<ObstacleModel>> obstacles;

    public:
        LaneModel(const std::weak_ptr<WorldModel>& worldModel, int laneIndex, const std::shared_ptr<HikerModel>& hiker);

        // Implementation of abstract function of interface AbstractLane
        void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) override;

        // Getters, setters and self-explanatory functions
        std::string toString();

        int getLaneIndex() const;

        void removeHiker(const std::shared_ptr<HikerModel>& hiker);
        void addHiker(const std::shared_ptr<HikerModel>& hiker);

        void addObstacle(const std::shared_ptr<ObstacleModel>& obstacle);
    };
}


#endif //TURBOHIKER_LANEMODEL_H
