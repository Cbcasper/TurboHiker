//
// Created by Casper De Smet on 13/12/2020.
//

#include "ModelHikerEvent.h"

using namespace std;

namespace turboHiker
{

    ModelHikerEvent::ModelHikerEvent(const string& message, int hikerIndex): ModelEvent(message, Event::HikerEvent), hikerIndex(hikerIndex)
    {

    }

    string ModelHikerEvent::what()
    {
        return message + ", of type ModelHikerEvent.";
    }

    int ModelHikerEvent::getHikerIndex()
    {
        return hikerIndex;
    }
}
