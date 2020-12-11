//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef PLAYGROUND_MODEL_H
#define PLAYGROUND_MODEL_H

#include <iostream>
#include "../Observer Pattern/Observable.h"

using namespace std;

namespace turboHiker
{
    class Controller;

    class Model: public Observable
    {
    public:
        Model();
        void notifyObservers() override;
    };
}


#endif //PLAYGROUND_MODEL_H
