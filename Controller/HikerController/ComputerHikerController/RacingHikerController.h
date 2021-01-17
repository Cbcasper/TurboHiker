//
// Created by Casper De Smet on 20/12/2020.
//

#ifndef TURBOHIKER_RACINGHIKERCONTROLLER_H
#define TURBOHIKER_RACINGHIKERCONTROLLER_H


#include "ComputerHikerController.h"
#include "../HikerController.h"

namespace turboHiker
{
    // Controller class that races the player hiker
    class RacingHikerController: public ComputerHikerController
    {
    private:
        // Function executed in separate thread
        void live() override;

    public:
        RacingHikerController(const std::weak_ptr<World>& world, int index);
        ~RacingHikerController() override = default;

        void handleEvent(const std::shared_ptr<Event>& event) override;
    };
}


#endif //TURBOHIKER_RACINGHIKERCONTROLLER_H
