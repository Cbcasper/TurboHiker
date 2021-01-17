//
// Created by Casper De Smet on 22/12/2020.
//

#include "GameView.h"

using namespace std;

namespace turboHiker
{
    GameView::GameView(const weak_ptr<WorldView>& worldView): onCountDown(false), countDown(3), worldView(worldView)
    {}
}