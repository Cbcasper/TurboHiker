//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_ADVERSARYHIKERVIEW_H
#define TURBOHIKER_ADVERSARYHIKERVIEW_H

#include "HikerView.h"

namespace turboHiker
{
    // Interface for an adversary hiker. Must be implemented to make the game presentation work
    class AdversaryHikerView: public virtual HikerView
    {
    public:
        AdversaryHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex);
    };
}


#endif //TURBOHIKER_ADVERSARYHIKERVIEW_H
