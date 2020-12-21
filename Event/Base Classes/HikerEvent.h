//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_HIKEREVENT_H
#define TURBOHIKER_HIKEREVENT_H



namespace turboHiker
{
    class HikerEvent
    {
    protected:
        int hikerIndex;

    public:
        enum HikerEventType {StartMoving, StopMoving, UpdateState, StateUpdated};

        HikerEventType hikerEventType;

        HikerEvent(int hikerIndex, HikerEventType hikerEventType);
    };
}


#endif //TURBOHIKER_HIKEREVENT_H
