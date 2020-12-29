//
// Created by Casper De Smet on 11/12/2020.
//

#include "LaneView.h"
#include "WorldView.h"

using namespace std;

namespace turboHiker
{
    LaneView::LaneView(const std::weak_ptr<WorldView>& worldView, int laneIndex, const list<shared_ptr<turboHiker::HikerView>>& hikers): worldView(worldView), index(laneIndex), hikers(hikers)
    {
        cout << "LaneView " << laneIndex << " is getting constructed!" << endl;
    }

    void LaneView::raiseEvent()
    {

    }

    LaneView::~LaneView()
    {
        cout << "This laneView is getting destructed." << endl;
    }
}