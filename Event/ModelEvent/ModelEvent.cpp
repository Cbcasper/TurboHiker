//
// Created by Casper De Smet on 13/12/2020.
//

#include "ModelEvent.h"

namespace turboHiker
{

    ModelEvent::ModelEvent(const std::string& message, Event::EventType eventType): Event(message, eventType)
    {}
}