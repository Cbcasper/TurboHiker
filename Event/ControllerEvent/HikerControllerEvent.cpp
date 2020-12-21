//
// Created by Casper De Smet on 20/12/2020.
//

#include "HikerControllerEvent.h"

turboHiker::HikerControllerEvent::HikerControllerEvent(int hikerIndex, HikerEventType hikerEventType, const std::string& message) :
        ControllerEvent(Event::HikerControllerEvent, message), HikerEvent(hikerIndex, hikerEventType)
{}

std::string turboHiker::HikerControllerEvent::what()
{
    return message;
}

int turboHiker::HikerControllerEvent::getIndex() const
{
    return hikerIndex;
}
