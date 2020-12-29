//
// Created by Casper De Smet on 25/12/2020.
//

#ifndef TURBOHIKER_ARROWKEYSSTATE_H
#define TURBOHIKER_ARROWKEYSSTATE_H

#include "../../Event/Event.h"

namespace turboHikerSFML
{
    class ArrowKeysState
    {
    private:
        bool upKeyPressed;
        bool downKeyPressed;
        bool leftKeyPressed;
        bool rightKeyPressed;

    public:
        bool keyPressed();
        void pressKey(turboHiker::Event::EventType direction);
        void releaseKey(turboHiker::Event::EventType direction);
    };
}


#endif //TURBOHIKER_ARROWKEYSSTATE_H
