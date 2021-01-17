//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_ADVERSARYHIKERMODEL_H
#define TURBOHIKER_ADVERSARYHIKERMODEL_H

#include "HikerModel.h"

namespace turboHiker
{
    class AdversaryHikerModel: public HikerModel
    {
    public:
        // An adversary hiker doesn't have a set initial location, so this can be passed through
        AdversaryHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex, double newX, double newY);
    };
}


#endif //TURBOHIKER_ADVERSARYHIKERMODEL_H
