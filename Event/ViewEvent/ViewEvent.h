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
        ViewEvent(EventType eventType, const std::string& message = "ViewEvent");
    };
}


#endif //TURBOHIKER_VIEWEVENT_H
