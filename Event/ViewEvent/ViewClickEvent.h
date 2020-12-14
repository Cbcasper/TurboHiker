//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_VIEWCLICKEVENT_H
#define TURBOHIKER_VIEWCLICKEVENT_H

#include "ViewEvent.h"

namespace turboHiker
{
    class ViewClickEvent: public ViewEvent
    {
    public:
        ViewClickEvent(const std::string& message);
        std::string what() override;
    };
}


#endif //TURBOHIKER_VIEWCLICKEVENT_H
