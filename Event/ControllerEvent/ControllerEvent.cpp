//
// Created by Casper De Smet on 20/12/2020.
//

#include "ControllerEvent.h"

turboHiker::ControllerEvent::ControllerEvent(EventType eventType, const std::string& message) :
        Event(message, eventType)
{

}
