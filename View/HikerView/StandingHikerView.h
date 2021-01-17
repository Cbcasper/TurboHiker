//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_STANDINGHIKERVIEW_H
#define TURBOHIKER_STANDINGHIKERVIEW_H

#include "HikerView.h"

namespace turboHiker
{
    // Interface for a standing hiker. Must be implemented to make the game presentation work
    class StandingHikerView: virtual public HikerView
    {
    public:
        StandingHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
    };
}


#endif //TURBOHIKER_STANDINGHIKERVIEW_H
