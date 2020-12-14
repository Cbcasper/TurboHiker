//
// Created by Casper De Smet on 11/12/2020.
//

#include "LaneView.h"
#include "WorldView.h"
#include "../Event/ViewEvent/ViewClickEvent.h"

using namespace std;

namespace turboHiker
{
    LaneView::LaneView(const shared_ptr<WorldView>& world, int index): world(world), index(index)
    {
        cout << "LaneView " << index << " is getting constructed!" << endl;
        laneTask = packaged_task<void()>(bind(&LaneView::startLiving, this));
        laneFuture = laneTask.get_future();
    }

    void LaneView::raiseEvent()
    {
        world->raiseEvent(make_shared<ViewClickEvent>("I was raised by lane worldView " + to_string(index)));
    }

    void LaneView::startLiving() const
    {
        stringstream output;
        output << "Lane " << index << " started living." << endl;
        cout << output.str();
    }

    void LaneView::start()
    {
        thread(move(laneTask)).detach();
    }

    void LaneView::wait()
    {
        laneFuture.wait();
    }
}