//
// Created by Casper De Smet on 11/12/2020.
//

#include "WorldView.h"
#include "../Controller/Controller.h"

namespace turboHiker
{

    WorldView::WorldView(const shared_ptr<Controller>& controller): controller(controller)
    {
        cout << "This world view is getting constructed." << endl;
        shared_ptr<WorldView> view = make_shared<WorldView>(*this);
        for (int i = 0; i < 4; ++i)
            lanes.emplace_back(make_shared<LaneView>(view, i));
    }

    void WorldView::raiseEvent(const shared_ptr<Event>& event)
    {
        cout << "World view says 'An event was raised: " << event->what() << "'" << endl;
        controller->raiseEvent(event);
    }

    const shared_ptr<LaneView>& WorldView::getLane(int index)
    {
        return lanes[index];
    }
}