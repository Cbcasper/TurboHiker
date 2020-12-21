//
// Created by Casper De Smet on 13/12/2020.
//

#include "HikerViewEvent.h"

using namespace std;

namespace turboHiker
{
    HikerViewEvent::HikerViewEvent(int hikerIndex, HikerEventType hikerEventType, const std::string& message) :
            ViewEvent(Event::HikerViewEvent, message), HikerEvent(hikerIndex, hikerEventType)
    {

    }

    string HikerViewEvent::what()
    {
        return "This is a hikerViewEvent with message: " + message;
    }

    int HikerViewEvent::getHikerIndex() const
    {
        return hikerIndex;
    }
}