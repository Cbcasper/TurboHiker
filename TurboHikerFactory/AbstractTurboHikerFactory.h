//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_ABSTRACTTURBOHIKERFACTORY_H
#define TURBOHIKER_ABSTRACTTURBOHIKERFACTORY_H

#include <memory>
#include "AbstractHiker.h"
#include "AbstractObstacle.h"
#include "AbstractWorldComponent.h"
#include "AbstractLane.h"
#include "../Controller/World.h"

namespace turboHiker
{
    class AbstractTurboHikerFactory
    {
    public:
        virtual std::shared_ptr<AbstractWorldComponent> createWorldComponent(const std::weak_ptr<World>& world, double width, double height) = 0;
        virtual std::shared_ptr<AbstractHiker> createHiker(int hikerIndex, World::HikerType hikerType, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) = 0;
        virtual std::shared_ptr<AbstractObstacle> createObstacle(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) = 0;
        virtual std::shared_ptr<AbstractLane> createLane(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, const std::shared_ptr<AbstractHiker>& hiker) = 0;
    };
}


#endif //TURBOHIKER_ABSTRACTTURBOHIKERFACTORY_H
