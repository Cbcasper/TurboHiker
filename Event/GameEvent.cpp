//
// Created by Casper De Smet on 19/12/2020.
//

#include "GameEvent.h"

namespace turboHiker
{
    GameEvent::GameEvent(GameEventType gameEventType, const std::string& message) : Event(message, Event::GameEvent), gameEventType(gameEventType)
    {}

    std::string GameEvent::what()
    {
        return message;
    }
}