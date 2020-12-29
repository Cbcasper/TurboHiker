//
// Created by Casper De Smet on 11/12/2020.
//

#include "WorldView.h"

using namespace std;

namespace turboHiker
{
    WorldView::WorldView(int screenX, int screenY): screenX(screenX), screenY(screenY)
    {}

//    void WorldView::raiseEvent(const shared_ptr<ViewEvent>& viewEvent)
//    {
//        stringstream message;
//        message << "WorldView says 'A viewEvent was raised: " << viewEvent->what() << "'" << endl;
//        cout << message.str();
//        world.lock()->raiseViewEvent(viewEvent);
//    }

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

    int WorldView::getScreenX()
    {
        return screenX;
    }

    int WorldView::getScreenY()
    {
        return screenY;
    }
}