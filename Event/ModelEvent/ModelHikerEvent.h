//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_MODELHIKEREVENT_H
#define TURBOHIKER_MODELHIKEREVENT_H

#include "ModelEvent.h"

namespace turboHiker
{
    class ModelHikerEvent : public ModelEvent
    {
    private:
        int hikerIndex;

    public:
        ModelHikerEvent(const std::string& message, int hikerIndex);
        std::string what() override;

        int getHikerIndex();
    };
}


#endif //TURBOHIKER_MODELHIKEREVENT_H
