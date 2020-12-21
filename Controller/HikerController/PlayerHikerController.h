//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERCONTROLLER_H
#define TURBOHIKER_PLAYERHIKERCONTROLLER_H

#include "HikerController.h"

namespace turboHiker
{
    class PlayerHikerController: public HikerController
    {
    private:
        bool moving;

        void live() override;

    public:
        PlayerHikerController(const std::weak_ptr<World>& world, int index);
        ~PlayerHikerController() override;

        void raiseEvent(const std::shared_ptr<Event>& event) override;
    };
}


#endif //TURBOHIKER_PLAYERHIKERCONTROLLER_H
