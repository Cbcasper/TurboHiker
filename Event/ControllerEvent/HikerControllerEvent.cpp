//
// Created by Casper De Smet on 20/12/2020.
//

#include "HikerControllerEvent.h"

turboHiker::HikerControllerEvent::HikerControllerEvent(int hikerIndex, HikerEventType hikerEventType, Direction direction, int newLaneIndex, const std::string& message) :
        ControllerEvent(Event::HikerControllerEvent, message), HikerEvent(hikerIndex, hikerEventType, direction), newLaneIndex(newLaneIndex)
{}

std::string turboHiker::HikerControllerEvent::what()
{
    return message;
}

int turboHiker::HikerControllerEvent::getNewLaneIndex() const
{
    return newLaneIndex;
}

