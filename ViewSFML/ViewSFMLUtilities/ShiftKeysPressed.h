//
// Created by Casper De Smet on 25/12/2020.
//

#ifndef TURBOHIKER_SHIFTKEYSPRESSED_H
#define TURBOHIKER_SHIFTKEYSPRESSED_H

#include <SFML/Window/Keyboard.hpp>
#include "../../Event/Event.h"

namespace turboHikerSFML
{
    class ShiftKeysPressed
    {
    private:
        // Flags for left and right shift key
        bool leftShiftPressed;
        bool rightShiftPressed;

    public:
        // Return whether any key is pressed
        bool keyPressed() const;
        // Press and release a key
        void pressKey(sf::Keyboard::Key key);
        void releaseKey(sf::Keyboard::Key key);
    };
}


#endif //TURBOHIKER_SHIFTKEYSPRESSED_H
