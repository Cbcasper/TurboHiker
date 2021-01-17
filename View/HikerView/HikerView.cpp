//
// Created by Casper De Smet on 13/12/2020.
//

#include "HikerView.h"
#include "../WorldView.h"

using namespace std;

namespace turboHiker
{
    HikerView::HikerView(const weak_ptr<WorldView>& worldView, int hikerIndex) :
            worldView(worldView), hikerIndex(hikerIndex)
    {}

    void HikerView::setCurrentLane(const weak_ptr<LaneView>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
    }

    int HikerView::getIndex() const
    {
        return hikerIndex;
    }

    int HikerView::getLaneIndex() const
    {
        return currentLane.lock()->getIndex();
    }
}