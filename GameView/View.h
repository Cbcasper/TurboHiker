//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef PLAYGROUND_VIEW_H
#define PLAYGROUND_VIEW_H

#include <iostream>
#include "../Observer Pattern/Observer.h"
#include "../Observer Pattern/Observable.h"

using namespace std;

namespace turboHiker
{
    class Controller;

    class View: public Observer, public Observable
    {
    public:
        View();
        void notifyObservers() override;
        void handleEvent() override;
    };
}


#endif //PLAYGROUND_VIEW_H
