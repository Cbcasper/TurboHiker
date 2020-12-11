//
// Created by Casper De Smet on 04/12/2020.
//

#include "View.h"
#include "../GameController/Controller.h"

namespace turboHiker
{
    View::View()
    {
        cout << "Constructing this view!" << endl;
    }

    void View::notifyObservers()
    {
        for (const shared_ptr<Observer>& observer: observers)
            observer->handleEvent();
    }

    void View::handleEvent()
    {

    }
}