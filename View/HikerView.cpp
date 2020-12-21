//
// Created by Casper De Smet on 13/12/2020.
//

#include "HikerView.h"
#include "WorldView.h"

using namespace std;

namespace turboHiker
{
    HikerView::HikerView(const weak_ptr<WorldView>& worldView, int hikerIndex) :
            worldView(worldView), hikerIndex(hikerIndex), x(float(hikerIndex) * 400 + 200), y(1300)
    {
        cout << "HikerView " << hikerIndex << " is getting constructed!" << endl;
    }

    void HikerView::raiseEvent()
    {
        stringstream message;
        message << "HikerView " << hikerIndex;
//        worldView.lock()->raiseEvent(make_shared<HikerViewEvent>(hikerIndex, message.str()));
    }

    void HikerView::setCurrentLane(const weak_ptr<LaneView>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
    }

    int HikerView::getIndex() const
    {
        return hikerIndex;
    }
}