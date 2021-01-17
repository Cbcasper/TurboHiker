//
// Created by Casper De Smet on 10/12/2020.
//

#include "LaneModel.h"
#include "ObstacleModel.h"

using namespace std;

namespace turboHiker
{
    LaneModel::LaneModel(const weak_ptr<WorldModel>& worldModel, int index, const shared_ptr<HikerModel>& hiker):
                         worldModel(worldModel), index(index), hikers({hiker})
    {}

    std::string LaneModel::toString()
    {
        // Print all hikers and obstacles
        stringstream output;
        output << "Lane " << index << " has hikers:" << endl;
        for (const shared_ptr<HikerModel>& hiker: hikers)
            output << "\t\t" << hiker->toString() << endl;
        output << "\tand obstacles:" << endl;
        for (const shared_ptr<ObstacleModel>& obstacle: obstacles)
            output << "\t\t" << obstacle->toString() << endl;
        return output.str();
    }

    int LaneModel::getLaneIndex() const
    {
        return index;
    }

    void LaneModel::removeHiker(const shared_ptr<HikerModel>& hiker)
    {
        hikers.remove(hiker);
    }

    void LaneModel::addObstacle(const shared_ptr<ObstacleModel>& obstacle)
    {
        obstacles.emplace_back(obstacle);
    }

    void LaneModel::addHiker(const shared_ptr<HikerModel>& hiker)
    {
        hikers.emplace_back(hiker);
    }

    void LaneModel::addObstacle(const shared_ptr<AbstractObstacle>& obstacle)
    {
        obstacles.emplace_back(dynamic_pointer_cast<ObstacleModel>(obstacle));
    }
}
