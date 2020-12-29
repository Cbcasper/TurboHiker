//
// Created by Casper De Smet on 13/12/2020.
//

#include "HikerModelEvent.h"
#include "../../Model/HikerModel/HikerModel.h"

using namespace std;

namespace turboHiker
{

    HikerModelEvent::HikerModelEvent(const std::shared_ptr<turboHiker::HikerModel>& hiker, HikerEventType hikerEventType,
                                     Direction direction, const std::string& message):
            ModelEvent(Event::HikerModelEvent, message), HikerEvent(hiker->getIndex(), hikerEventType, direction), hiker(hiker)
    {

    }

    string HikerModelEvent::what()
    {
        return "This is a modelHikerEvent with message: " + message;
    }

    float HikerModelEvent::getHikerX()
    {
        return float(hiker->getX());
    }

    float HikerModelEvent::getHikerY()
    {
        return float(hiker->getY());
    }

    int HikerModelEvent::getHikerIndex() const
    {
        return hikerIndex;
    }
}