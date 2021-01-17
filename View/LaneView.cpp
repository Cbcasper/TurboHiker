//
// Created by Casper De Smet on 11/12/2020.
//

#include "LaneView.h"
#include "WorldView.h"
#include "ObstacleView.h"

using namespace std;

namespace turboHiker
{
    LaneView::LaneView(const std::weak_ptr<WorldView>& worldView, int laneIndex, const shared_ptr<turboHiker::HikerView>& hiker): worldView(worldView), index(laneIndex), hikers({hiker})
    {}

    int LaneView::getIndex() const
    {
        return index;
    }

    void LaneView::removeHiker(const shared_ptr<HikerView>& hiker)
    {
        hikers.remove(hiker);
    }

    void LaneView::addObstacle(const shared_ptr<ObstacleView>& obstacle)
    {
        obstacles.emplace_back(obstacle);
    }

    void LaneView::addHiker(const shared_ptr<HikerView>& hiker)
    {
        hikers.emplace_back(hiker);
        hiker->setCurrentLane(shared_from_this());
    }

    void LaneView::addObstacle(const shared_ptr<AbstractObstacle>& obstacle)
    {
        obstacles.emplace_back(dynamic_pointer_cast<ObstacleView>(obstacle));
    }
}