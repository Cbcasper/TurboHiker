//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef PLAYGROUND_CONTROLLER_H
#define PLAYGROUND_CONTROLLER_H

#include <iostream>
#include <memory>
#include "../GameModel/Model.h"
#include "../GameView/View.h"

using namespace std;

namespace turboHiker
{
    class Controller: public Observer
    {
    public:
        Controller();
        void handleEvent() override;
    };
}


#endif //PLAYGROUND_CONTROLLER_H
