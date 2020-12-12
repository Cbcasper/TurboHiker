//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_EVENT_H
#define TURBOHIKER_EVENT_H

#include <string>

using namespace std;

namespace turboHiker
{
    class Event
    {
    protected:
        string message;

    public:
        Event(const string& message);
        virtual string what();
    };
}


#endif //TURBOHIKER_EVENT_H
