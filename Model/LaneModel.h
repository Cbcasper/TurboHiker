//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_LANEMODEL_H
#define TURBOHIKER_LANEMODEL_H

#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include "HikerModel.h"

namespace turboHiker
{
    class WorldModel;

    class LaneModel
    {
    private:
        int index;

        std::weak_ptr<WorldModel> worldModel;
        std::list<std::shared_ptr<HikerModel>> hikers;

    public:
        LaneModel(const std::weak_ptr<WorldModel>& worldModel, int laneIndex, const std::list<std::shared_ptr<HikerModel>>& hikers);

        std::string toString();

        template<class ...Hikers> void addHikers(const Hikers& ...newHikers)
        {
            std::list<std::shared_ptr<HikerModel>> newHikerList = {newHikers...};
            for (const std::shared_ptr<HikerModel>& hiker: newHikerList)
                hikers.emplace_back(hiker);
        }
    };
}


#endif //TURBOHIKER_LANEMODEL_H
