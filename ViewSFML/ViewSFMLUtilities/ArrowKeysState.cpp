//
// Created by Casper De Smet on 25/12/2020.
//

#include "ArrowKeysState.h"

namespace turboHikerSFML
{
    bool ArrowKeysState::keyPressed()
    {
        return upKeyPressed && downKeyPressed && leftKeyPressed && rightKeyPressed;
    }

    void ArrowKeysState::pressKey(turboHiker::Event::EventType direction)
    {
        switch (direction)
        {
            case turboHiker::Event::MoveLeft:       leftKeyPressed = true;     break;
            case turboHiker::Event::MoveRight:      rightKeyPressed = true;    break;
            case turboHiker::Event::MoveForward:    upKeyPressed = true;       break;
            default:                                                           break;
        }
    }

    void ArrowKeysState::releaseKey(turboHiker::Event::EventType direction)
    {
        switch (direction)
        {
            case turboHiker::Event::MoveLeft:       leftKeyPressed = false;    break;
            case turboHiker::Event::MoveRight:      rightKeyPressed = false;   break;
            case turboHiker::Event::MoveForward:    upKeyPressed = false;      break;
            default:                                                           break;
        }
    }
}