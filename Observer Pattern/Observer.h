//
// Created by Casper De Smet on 25/11/2020.
//

#ifndef PLAYGROUND_OBSERVER_H
#define PLAYGROUND_OBSERVER_H

namespace turboHiker
{
    class Observer
    {
    public:
        virtual void handleEvent() = 0;
    };
}


#endif //PLAYGROUND_OBSERVER_H
