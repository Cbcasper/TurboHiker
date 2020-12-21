//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_WORLDMODEL_H
#define TURBOHIKER_WORLDMODEL_H

#include <vector>
#include <memory>
#include <string>
#include "LaneModel.h"
#include "HikerModel.h"
#include "../Event/ModelEvent/ModelEvent.h"
#include "../Event/ViewEvent/ViewEvent.h"

namespace turboHiker
{
    class World;

    class WorldModel
    {
    private:
        std::weak_ptr<World> world;
        std::vector<std::shared_ptr<LaneModel>> lanes;
        std::vector<std::shared_ptr<HikerModel>> hikers;

    public:
        WorldModel(const std::weak_ptr<World>& world);

        void raiseEvent(const std::shared_ptr<ModelEvent>& event);

        std::shared_ptr<HikerModel> constructHiker(int hikerIndex, const std::weak_ptr<WorldModel>& worldModel);
        void constructLane(int laneIndex, const std::weak_ptr<WorldModel>& worldModel, const std::list<std::shared_ptr<HikerModel>>& hikerList);

        std::string toString();

        const std::shared_ptr<HikerModel>& getHiker(int hikerIndex);
    };
}

#endif //TURBOHIKER_WORLDMODEL_H
