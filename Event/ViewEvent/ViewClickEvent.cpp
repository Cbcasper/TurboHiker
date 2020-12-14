//
// Created by Casper De Smet on 11/12/2020.
//

#include "ViewClickEvent.h"

using namespace std;

namespace turboHiker
{
    ViewClickEvent::ViewClickEvent(const string& message) : ViewEvent(message, Event::ClickEvent)
    {

    }

    string turboHiker::ViewClickEvent::what()
    {
        return message + ", of type Click Event";
    }
}
