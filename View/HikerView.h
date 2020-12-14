//
// Created by Casper De Smet on 13/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEW_H
#define TURBOHIKER_HIKERVIEW_H

#include <memory>
#include <iostream>
#include "../Event/ModelEvent/ModelEvent.h"

namespace turboHiker
{
    class WorldView;

    class HikerView
    {
    private:
        int hikerIndex;
        std::shared_ptr<WorldView> worldModel;

    public:
        HikerView(const std::shared_ptr<WorldView>& worldModel, int hikerIndex);
        void receiveEvent(const std::shared_ptr<ModelEvent>& event);
    };
}


#endif //TURBOHIKER_HIKERVIEW_H
