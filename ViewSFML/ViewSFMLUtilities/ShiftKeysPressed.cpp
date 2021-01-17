//
// Created by Casper De Smet on 25/12/2020.
//

#include "ShiftKeysPressed.h"

namespace turboHikerSFML
{
    bool ShiftKeysPressed::keyPressed() const
    {
        // If any key is pressed, return true
        return leftShiftPressed || rightShiftPressed;
    }

    void ShiftKeysPressed::pressKey(sf::Keyboard::Key key)
    {
        // Determine which key is pressed and set it
        switch (key)
        {
            case sf::Keyboard::LShift: leftShiftPressed = true;     break;
            case sf::Keyboard::RShift: rightShiftPressed = true;    break;
            default:                                                break;
        }
    }

    void ShiftKeysPressed::releaseKey(sf::Keyboard::Key key)
    {
        // Determine which key is released and set it
        switch (key)
        {
            case sf::Keyboard::LShift: leftShiftPressed = false;     break;
            case sf::Keyboard::RShift: rightShiftPressed = false;    break;
            default:                                                 break;
        }
    }
}