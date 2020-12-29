//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERVIEW_H
#define TURBOHIKER_PLAYERHIKERVIEW_H

#include "HikerView.h"

namespace turboHiker
{
    class PlayerHikerView: virtual public HikerView
    {
    public:
        PlayerHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
    };
}


#endif //TURBOHIKER_PLAYERHIKERVIEW_H
