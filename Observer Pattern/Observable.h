//
// Created by Casper De Smet on 25/11/2020.
//

#ifndef PLAYGROUND_OBSERVABLE_H
#define PLAYGROUND_OBSERVABLE_H

#include <list>
#include "Observer.h"

using namespace std;

namespace turboHiker
{
    class Observable
    {
    public:
        void addObserver(const shared_ptr<Observer>& observer);
        void removeObserver(const shared_ptr<Observer>& observer);

        virtual void notifyObservers() = 0;

    protected:
        list<shared_ptr<Observer>> observers;
    };
}

#endif //PLAYGROUND_OBSERVABLE_H
