//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_ABSTRACTWORLDCOMPONENT_H
#define TURBOHIKER_ABSTRACTWORLDCOMPONENT_H

#include <memory>
#include "AbstractHiker.h"
#include "AbstractObstacle.h"
#include "AbstractLane.h"

namespace turboHiker
{
    class AbstractWorldComponent
    {
    public:
        virtual void addHiker(const std::shared_ptr<AbstractHiker>& hiker) = 0;
        virtual void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) = 0;
        virtual void addLane(const std::shared_ptr<AbstractLane>& lane) = 0;

        virtual std::shared_ptr<AbstractLane> getAbstractLane(int laneIndex) = 0;
    };
}


#endif //TURBOHIKER_ABSTRACTWORLDCOMPONENT_H
