//
// Created by Casper De Smet on 21/12/2020.
//

#include "HikerEvent.h"

int turboHiker::HikerEvent::getHikerIndex() const
{
    return hikerIndex;
}

namespace turboHiker
{
    HikerEvent::HikerEvent(int hikerIndex, HikerEventType hikerEventType, Direction direction):
            hikerIndex(hikerIndex), hikerEventType(hikerEventType), direction(direction)
    {}
}