//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_LANEVIEW_H
#define TURBOHIKER_LANEVIEW_H

#include <iostream>

using namespace std;

namespace turboHiker
{
    class WorldView;

    class LaneView
    {
    private:
        int index;
        shared_ptr<WorldView> world;

    public:
        LaneView(const shared_ptr<WorldView>& world, int index);
        void raiseEvent();
    };
}


#endif //TURBOHIKER_LANEVIEW_H
