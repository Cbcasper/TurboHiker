//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERMODEL_H
#define TURBOHIKER_HIKERMODEL_H

#include <memory>
#include <future>
#include <thread>
#include <iostream>
#include <vector>
#include "Hitbox.h"
#include "../../Event/Event.h"
#include "../../Utilities/Transformation.h"
#include "../../TurboHikerFactory/AbstractHiker.h"

namespace turboHiker
{
    class WorldModel;
    class LaneModel;
    class ObstacleModel;

    class HikerModel: public AbstractHiker, public std::enable_shared_from_this<HikerModel>
    {
    protected:
        int hikerIndex;

        // Position
        double x;
        double y;
        // Amount the hiker moves with at once
        const double stride;

        bool moving;

        std::shared_ptr<Hitbox> hitbox;

        std::weak_ptr<WorldModel> worldModel;
        std::weak_ptr<LaneModel> currentLane;

    public:
        HikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex);
        virtual ~HikerModel() = default;

        void setCurrentLane(const std::weak_ptr<LaneModel>& givenCurrentLane);
        void initializeCurrentLane(const std::weak_ptr<LaneModel>& givenCurrentLane);

        virtual void handleEvent(const std::shared_ptr<Event>& event);

        std::string toString() const;

        double getX() const;
        double getY() const;

        int getIndex() const;
        int getLaneIndex() const;

        std::shared_ptr<LaneModel> getLane();

        // Check if it collides with a hiker or an obstacle
        bool collidesWith(const std::shared_ptr<HikerModel>& hiker);
        bool collidesWith(const std::shared_ptr<ObstacleModel>& obstacle);

        std::pair<float, float> getHitboxSize();
        void setHitboxSize(const std::pair<float, float>& hitboxSize);

        double getHitboxWidth();
        double getHitboxHeight();

        const std::shared_ptr<Hitbox>& getHitbox() const;

        bool finished() const;

        bool isMoving() const;
        void setMoving(bool newValue);
    };
}


#endif //TURBOHIKER_HIKERMODEL_H
