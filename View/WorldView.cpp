//
// Created by Casper De Smet on 11/12/2020.
//

#include "WorldView.h"
#include "../Controller/World.h"

using namespace std;

namespace turboHiker
{

    WorldView::WorldView()
    {
        cout << "This worldView is getting constructed." << endl;
        shared_ptr<WorldView> view = make_shared<WorldView>(*this);
        for (int i = 0; i < 4; ++i)
        {
            lanes.emplace_back(make_shared<LaneView>(view, i));
            hikers.emplace_back(make_shared<HikerView>(view, i));
        }
    }

    void WorldView::raiseEvent(const shared_ptr<ViewEvent>& viewEvent)
    {
        cout << "WorldView says 'An viewEvent was raised: " << viewEvent->what() << "'" << endl;
        world->raiseViewEvent(viewEvent);
    }

    const shared_ptr<LaneView>& WorldView::getLane(int index)
    {
        return lanes[index];
    }

    void WorldView::start()
    {
        for (const shared_ptr<LaneView>& lane: lanes)
            lane->start();
    }

    void WorldView::wait()
    {
        for (const shared_ptr<LaneView>& lane: lanes)
            lane->wait();
    }

    void WorldView::setWorld(const shared_ptr<World>& controller)
    {
        this->world = controller;
    }

    const std::shared_ptr<HikerView>& WorldView::getHiker(int index)
    {
        return hikers[index];
    }
}