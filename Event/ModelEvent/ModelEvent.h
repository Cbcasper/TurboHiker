//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_MODELEVENT_H
#define TURBOHIKER_MODELEVENT_H

#include "../Event.h"

namespace turboHiker
{
    class ModelEvent: public Event
    {
    public:
        ModelEvent(EventType eventType, const std::string& message = "ModelEvent");
    };
}

#endif //TURBOHIKER_MODELEVENT_H
