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
    }

    void WorldView::raiseEvent(const shared_ptr<ViewEvent>& viewEvent)
    {
        stringstream message;
        message << "WorldView says 'An viewEvent was raised: " << viewEvent->what() << "'" << endl;
//        cout << message.str();
        world.lock()->raiseViewEvent(viewEvent);
    }

    const shared_ptr<LaneView>& WorldView::getLane(int index)
    {
        return lanes[index];
    }

    void WorldView::setWorld(const weak_ptr<World>& givenWorld)
    {
        this->world = givenWorld;
    }

    const std::shared_ptr<HikerView>& WorldView::getHiker(int index)
    {
        return hikers[index];
    }
}