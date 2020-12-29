//
// Created by Casper De Smet on 19/12/2020.
//

#ifndef TURBOHIKER_GAMEEVENT_H
#define TURBOHIKER_GAMEEVENT_H

#include "Event.h"

namespace turboHiker
{
    class GameEvent: public Event
    {
    public:
        enum GameEventType {StartCountDown, CountDown, Start, Stop, ForcedStop};

        GameEventType gameEventType;

        explicit GameEvent(GameEventType gameEventType, const std::string& message = "GameEvent");

        std::string what() override;
    };
}


#endif //TURBOHIKER_GAMEEVENT_H
