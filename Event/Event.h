//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_EVENT_H
#define TURBOHIKER_EVENT_H

#include <string>

namespace turboHiker
{
    class Event
    {
    public:
        enum EventType {ClickEvent, HikerEvent};

    protected:
        std::string message;

    public:
        EventType eventType;

        Event(const std::string& message, EventType eventType);

        virtual std::string what() = 0;
    };
}


#endif //TURBOHIKER_EVENT_H
