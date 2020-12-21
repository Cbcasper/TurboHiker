//
// Created by Casper De Smet on 13/12/2020.
//

#include "ModelEvent.h"

namespace turboHiker
{

    ModelEvent::ModelEvent(EventType eventType, const std::string& message): Event(message, eventType)
    {}
}