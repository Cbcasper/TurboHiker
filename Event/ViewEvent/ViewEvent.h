//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_VIEWEVENT_H
#define TURBOHIKER_VIEWEVENT_H

#include "../Event.h"

namespace turboHiker
{
    class ViewEvent: public Event
    {
    public:
        ViewEvent(const std::string& message, EventType eventType);
    };
}


#endif //TURBOHIKER_VIEWEVENT_H
