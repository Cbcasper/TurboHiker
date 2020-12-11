//
// Created by Casper De Smet on 04/12/2020.
//

#include "Model.h"
#include "../GameController/Controller.h"

namespace turboHiker
{
    Model::Model()
    {
        cout << "Constructing this model!" << endl;
    }

    void Model::notifyObservers()
    {
        for (const shared_ptr<Observer>& observer: observers)
            observer->handleEvent();
    }
}
