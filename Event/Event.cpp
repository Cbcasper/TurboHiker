//
// Created by Casper De Smet on 11/12/2020.
//

#include "Event.h"

using namespace std;

namespace turboHiker
{
    Event::Event(const string& message, EventType eventType): message(message), eventType(eventType)
    {}

    string Event::what()
    {
        return "Event: " + message;
    }
}