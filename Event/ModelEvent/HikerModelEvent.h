//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERMODELEVENT_H
#define TURBOHIKER_HIKERMODELEVENT_H

#include "ModelEvent.h"
#include "../Base Classes/HikerEvent.h"

namespace turboHiker
{
    class HikerModel;

    class HikerModelEvent: public ModelEvent, public HikerEvent
    {
    private:
        std::shared_ptr<turboHiker::HikerModel> hiker;

    public:
        HikerModelEvent(const std::shared_ptr<turboHiker::HikerModel>& hiker, HikerEventType hikerEventType,
                        const std::string& message = "HikerModelEvent");
        std::string what() override;

        float getHikerX();
        float getHikerY();

        int getHikerIndex() const;
    };
}


#endif //TURBOHIKER_HIKERMODELEVENT_H
