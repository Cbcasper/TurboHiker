//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERCONTROLLER_H
#define TURBOHIKER_PLAYERHIKERCONTROLLER_H

#include <map>
#include "HikerController.h"
#include "../../Event/Event.h"

namespace turboHiker
{
    class PlayerHikerController: public HikerController
    {
    private:
        bool moving;
//        HikerEvent::Direction direction;

        void live() override;

    public:
        PlayerHikerController(const std::weak_ptr<World>& world, int index);
        ~PlayerHikerController() override;

        void handleEvent(const std::shared_ptr<Event>& event) override;

        void changeLaneIndex(Event::EventType direction);
    };
}


#endif //TURBOHIKER_PLAYERHIKERCONTROLLER_H
