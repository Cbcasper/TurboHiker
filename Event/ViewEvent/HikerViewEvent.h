//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEWEVENT_H
#define TURBOHIKER_HIKERVIEWEVENT_H

#include "ViewEvent.h"
#include "../Base Classes/HikerEvent.h"

namespace turboHiker
{
    class HikerViewEvent: public ViewEvent, public HikerEvent
    {
    public:
        HikerViewEvent(int hikerIndex, HikerEventType hikerEventType, Direction direction = NoDirection, const std::string& message = "HikerViewEvent");
        std::string what() override;

        int getHikerIndex() const;
    };
}


#endif //TURBOHIKER_HIKERVIEWEVENT_H
