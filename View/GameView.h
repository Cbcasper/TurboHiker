//
// Created by Casper De Smet on 22/12/2020.
//

#ifndef TURBOHIKER_GAMEVIEW_H
#define TURBOHIKER_GAMEVIEW_H

#include <memory>
#include <iostream>
#include "../Event/Event.h"

namespace turboHiker
{
    class WorldView;

    // Interface for the view of the game. Needs to be implemented for the game presentation to work
    class GameView
    {
    protected:
        // Link to parent object
        std::weak_ptr<WorldView> worldView;

        // Whether the game is on count down and what the count down is
        bool onCountDown;
        int countDown;

    public:
        explicit GameView(const std::weak_ptr<WorldView>& worldView);
        virtual ~GameView() = default;

        // Abstract functions that will be called by the world
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;
        virtual void setFinishLinePosition(double x, double y) = 0;
        // Move the portion of the world visible
        virtual void scroll(double yOffset) = 0;
    };
}


#endif //TURBOHIKER_GAMEVIEW_H
