//
// Created by Casper De Smet on 13/12/2020.
//

#include "ViewHikerEvent.h"

using namespace std;

namespace turboHiker
{
    ViewHikerEvent::ViewHikerEvent(const string& message, int hikerIndex): ViewEvent(message, Event::HikerEvent), hikerIndex(hikerIndex)
    {

    }

    string ViewHikerEvent::what()
    {
        return message + ", of type Hiker Event.";
    }
}