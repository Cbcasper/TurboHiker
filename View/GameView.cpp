//
// Created by Casper De Smet on 22/12/2020.
//

#include "GameView.h"

using namespace std;

namespace turboHiker
{
    GameView::GameView(): onCountDown(false), countDown(3)
    {}

    GameView::~GameView()
    {
        cout << "GameView is getting destructed." << endl;
    }
}