//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_ABSTRACTLANE_H
#define TURBOHIKER_ABSTRACTLANE_H

#include <memory>
#include "AbstractObstacle.h"

namespace turboHiker
{
    class AbstractLane
    {
    public:
        virtual ~AbstractLane() = default;

        virtual void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) = 0;
    };
}


#endif //TURBOHIKER_ABSTRACTLANE_H
