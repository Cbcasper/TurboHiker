//
// Created by Casper De Smet on 13/12/2020.
//

#include "ViewEvent.h"

namespace turboHiker
{
    ViewEvent::ViewEvent(EventType eventType, const std::string& message) : Event(message, eventType)
    {

    }
}