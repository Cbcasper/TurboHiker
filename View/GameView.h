//
// Created by Casper De Smet on 22/12/2020.
//

#ifndef TURBOHIKER_GAMEVIEW_H
#define TURBOHIKER_GAMEVIEW_H

#include <memory>
#include <iostream>
#include "../Event/GameEvent.h"

namespace turboHiker
{
    class GameView
    {
    protected:
        bool onCountDown;
        int countDown;

    public:
        GameView();
        virtual ~GameView();

//        virtual void receiveGameEvent(const std::shared_ptr<GameEvent>& event) = 0;
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;
    };
}


#endif //TURBOHIKER_GAMEVIEW_H
