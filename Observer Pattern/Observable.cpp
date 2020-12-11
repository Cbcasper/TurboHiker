//
// Created by Casper De Smet on 25/11/2020.
//

#include "Observable.h"

namespace turboHiker
{
    void Observable::addObserver(const shared_ptr<Observer>& observer)
    {
        observers.emplace_back(observer);
    }

    void Observable::removeObserver(const shared_ptr<Observer>& observer)
    {
        observers.remove(observer);
    }
}

