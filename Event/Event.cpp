//
// Created by Casper De Smet on 11/12/2020.
//

#include "Event.h"
#include "../Model/HikerModel/HikerModel.h"

using namespace std;

namespace turboHiker
{
    Event::Event(EventType eventType, const string& message): message(message), eventType(eventType), hikerIndex(0), hiker(nullptr)
    {}

    Event::Event(Event::EventType eventType, int hikerIndex, const std::string& message): eventType(eventType), hikerIndex(hikerIndex), message(message), hiker(nullptr)
    {}

    Event::Event(EventType eventType, const shared_ptr<HikerModel>& hiker, const std::string& message): eventType(eventType), hiker(hiker), message(message), hikerIndex(0)
    {}

    string Event::what()
    {
        return "Event: " + message;
    }

    int Event::getHikerIndex() const
    {
        return hikerIndex;
    }

    double Event::getHikerX() const
    {
        return hiker->getX();
    }

    double Event::getHikerY() const
    {
        return hiker->getY();
    }
}