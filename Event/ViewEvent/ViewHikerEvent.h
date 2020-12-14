//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_VIEWHIKEREVENT_H
#define TURBOHIKER_VIEWHIKEREVENT_H

#include "ViewEvent.h"

namespace turboHiker
{
    class ViewHikerEvent: public ViewEvent
    {
    private:
        int hikerIndex;

    public:
        ViewHikerEvent(const std::string& message, int hikerIndex);
        std::string what() override;
    };
}


#endif //TURBOHIKER_VIEWHIKEREVENT_H
