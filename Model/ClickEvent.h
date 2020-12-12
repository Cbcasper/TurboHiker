//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_CLICKEVENT_H
#define TURBOHIKER_CLICKEVENT_H

#include "Event.h"

namespace turboHiker
{
    class ClickEvent: public Event
    {

    public:
        ClickEvent(const string& message);
        string what() override;
    };
}


#endif //TURBOHIKER_CLICKEVENT_H
