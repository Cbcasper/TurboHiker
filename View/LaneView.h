//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_LANEVIEW_H
#define TURBOHIKER_LANEVIEW_H

#include <iostream>
#include <future>
#include <thread>
#include <sstream>
#include <memory>
#include <list>

namespace turboHiker
{
    class WorldView;
    class HikerView;

    class LaneView
    {
    protected:
        std::weak_ptr<WorldView> worldView;
        std::list<std::shared_ptr<HikerView>> hikers;

        int index;
    public:
        LaneView(const std::weak_ptr<WorldView>& world, int laneIndex, const std::list<std::shared_ptr<turboHiker::HikerView>>& hikers);

        void raiseEvent();

        virtual ~LaneView();

        template<class ...Hikers> void addHikers(const Hikers& ...newHikers)
        {
            std::list<std::shared_ptr<HikerView>> newHikerList = {newHikers...};
            for (const std::shared_ptr<HikerView>& hiker: newHikerList)
                hikers.emplace_back(hiker);
        }
    };
}


#endif //TURBOHIKER_LANEVIEW_H
