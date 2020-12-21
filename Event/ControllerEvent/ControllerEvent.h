//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_CONTROLLEREVENT_H
#define TURBOHIKER_CONTROLLEREVENT_H

#include "../Event.h"

namespace turboHiker
{
    class ControllerEvent: public Event
    {
    public:
        ControllerEvent(EventType eventType, const std::string& message = "ControllerEvent");
    };
}

#endif //TURBOHIKER_CONTROLLEREVENT_H
