//
// Created by Casper De Smet on 16/01/2021.
//

#ifndef TURBOHIKER_ADVERSARYHIKERCONTROLLER_H
#define TURBOHIKER_ADVERSARYHIKERCONTROLLER_H

#include "ComputerHikerController.h"
#include "../HikerController.h"

namespace turboHiker
{
    // Controller class for hikers moving toward the player
    class AdversaryHikerController: public ComputerHikerController
    {
    protected:
        // Function executed in separate thread
        void live() override;

    public:
        AdversaryHikerController(const std::weak_ptr<World>& world, int index);

        void handleEvent(const std::shared_ptr<Event>& event) override;
    };
}


#endif //TURBOHIKER_ADVERSARYHIKERCONTROLLER_H
