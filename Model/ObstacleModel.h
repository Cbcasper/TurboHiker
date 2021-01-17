//
// Created by Casper De Smet on 11/01/2021.
//

#ifndef TURBOHIKER_OBSTACLEMODEL_H
#define TURBOHIKER_OBSTACLEMODEL_H

#include <memory>
#include "LaneModel.h"
#include "../TurboHikerFactory/AbstractObstacle.h"

namespace turboHiker
{
    class ObstacleModel: public AbstractObstacle
    {
    protected:
        int index;

        double x;
        double y;

        std::shared_ptr<Hitbox> hitbox;

        // Flag to check whether it's broken
        bool broken;

        std::weak_ptr<WorldModel> worldModel;
        std::weak_ptr<LaneModel> currentLane;

    public:
        // An obstacle spawns in at a given position
        ObstacleModel(const std::weak_ptr<WorldModel>& worldModel, const std::weak_ptr<LaneModel>& laneModel, double x, double y);

        void setHitboxSize(const std::pair<float, float>& hitboxSize);

        double getX() const;
        double getY() const;

        double getHitboxWidth();
        double getHitboxHeight();
        const std::shared_ptr<Hitbox>& getHitbox() const;

        int getIndex() const;

        std::string toString();

        void goBroken();
        bool isBroken() const;
    };
}


#endif //TURBOHIKER_OBSTACLEMODEL_H
