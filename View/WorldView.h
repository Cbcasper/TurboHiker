//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEW_H
#define TURBOHIKER_WORLDVIEW_H

#include <vector>
#include <memory>
#include <iostream>
#include "LaneView.h"
#include "../Model/Event.h"

using namespace std;

namespace turboHiker
{
    class Controller;

    class WorldView
    {
    private:
        shared_ptr<Controller> controller;
        vector<shared_ptr<LaneView>> lanes;

    public:
        WorldView(const shared_ptr<Controller>& controller);
        void raiseEvent(const shared_ptr<Event>& event);

        const shared_ptr<LaneView>& getLane(int index);
    };
}


#endif //TURBOHIKER_WORLDVIEW_H
