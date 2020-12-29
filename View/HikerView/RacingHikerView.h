//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_RACINGHIKERVIEW_H
#define TURBOHIKER_RACINGHIKERVIEW_H

#include "HikerView.h"

namespace turboHiker
{
    class RacingHikerView: virtual public HikerView
    {
    public:
        RacingHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
    };
}


#endif //TURBOHIKER_RACINGHIKERVIEW_H