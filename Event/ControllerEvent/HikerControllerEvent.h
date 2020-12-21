//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_HIKERCONTROLLEREVENT_H
#define TURBOHIKER_HIKERCONTROLLEREVENT_H

#include "ControllerEvent.h"
#include "../Base Classes/HikerEvent.h"

namespace turboHiker
{
    class HikerControllerEvent: public ControllerEvent, public HikerEvent
    {
    public:
        HikerControllerEvent(int hikerIndex, HikerEventType hikerEventType, const std::string& message = "HikerControllerEvent");

        std::string what() override;

        int getIndex() const;
    };
}


#endif //TURBOHIKER_HIKERCONTROLLEREVENT_H
