//
// Created by Casper De Smet on 11/12/2020.
//

#include "LaneView.h"
#include "WorldView.h"
#include "../Model/ClickEvent.h"

namespace turboHiker
{
    LaneView::LaneView(const shared_ptr<WorldView>& world, int index): world(world), index(index)
    {
        cout << "Lane view " << index << " is getting constructed!" << endl;
    }

    void LaneView::raiseEvent()
    {
        world->raiseEvent(make_shared<ClickEvent>("I was raised by lane view " + to_string(index)));
    }
}