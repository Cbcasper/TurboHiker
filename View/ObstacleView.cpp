//
// Created by Casper De Smet on 11/01/2021.
//

#include "ObstacleView.h"

using namespace std;

namespace turboHiker
{
    ObstacleView::ObstacleView(const weak_ptr<WorldView>& worldView, const weak_ptr<LaneView>& currentLane):
                               worldView(worldView), currentLane(currentLane)
    {
        // Each obstacle has a unique index. Because the obstacles are created simultaneous in the world and view, the index will match
        static int indexGenerator = 0;
        index = indexGenerator;
        indexGenerator++;
    }
}
