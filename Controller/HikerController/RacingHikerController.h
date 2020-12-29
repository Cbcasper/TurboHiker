//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_RACINGHIKERCONTROLLER_H
#define TURBOHIKER_RACINGHIKERCONTROLLER_H


#include "HikerController.h"

namespace turboHiker
{
    class RacingHikerController: public HikerController
    {
    private:
        void live() override;

    public:
        RacingHikerController(const std::weak_ptr<World>& world, int index);
        ~RacingHikerController() override;

        void handleEvent(const std::shared_ptr<Event>& event) override;
    };
}


#endif //TURBOHIKER_RACINGHIKERCONTROLLER_H
