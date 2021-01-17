//
// Created by Casper De Smet on 11/01/2021.
//

#ifndef TURBOHIKER_OBSTACLEVIEW_H
#define TURBOHIKER_OBSTACLEVIEW_H

#include <memory>
#include "WorldView.h"

namespace turboHiker
{
    // Interface for the view of an obstacle. Must be implemented to make the presentation work
    class ObstacleView: public AbstractObstacle
    {
    protected:
        int index;

        // Link to parent objects
        std::weak_ptr<WorldView> worldView;
        std::weak_ptr<LaneView> currentLane;

    public:
        ObstacleView(const std::weak_ptr<WorldView>& worldView, const std::weak_ptr<LaneView>& currentLane);

        // Abstract functions that the world will call
        virtual std::pair<float, float> getHitboxSize() = 0;
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;
    };
}


#endif //TURBOHIKER_OBSTACLEVIEW_H
