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
        enum HikerEventType {NoEvent, Move, SpeedUp, SpeedDown, UpdateState, StateUpdated};
        enum Direction {NoDirection, Left, Right, Forward};

        HikerEventType hikerEventType;
        Direction direction;

        HikerEvent(int hikerIndex, HikerEventType hikerEventType, Direction direction);

        int getHikerIndex() const;
    };
}


#endif //TURBOHIKER_HIKEREVENT_H
