//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_WORLDMODEL_H
#define TURBOHIKER_WORLDMODEL_H

#include <vector>
#include <memory>
#include "LaneModel.h"
#include "HikerModel.h"
#include "../Event/ModelEvent/ModelEvent.h"

namespace turboHiker
{
    class World;

    class WorldModel
    {
    private:
        std::shared_ptr<World> world;
        std::vector<std::shared_ptr<LaneModel>> lanes;
        std::vector<std::shared_ptr<HikerModel>> hikers;
    public:
        bool inWait;

    public:
        WorldModel(const std::shared_ptr<World>& world);

        void start();
        void wait();

        void raiseEvent(const std::shared_ptr<ModelEvent>& event);
        bool isInWait() const;
    };
}

#endif //TURBOHIKER_WORLDMODEL_H
