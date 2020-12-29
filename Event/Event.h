//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_EVENT_H
#define TURBOHIKER_EVENT_H

#include <string>

namespace turboHiker
{
    class HikerModel;

    class Event
    {
    protected:
        std::string message;

        int hikerIndex;
        std::shared_ptr<HikerModel> hiker;

    public:
        enum EventType
        {
            StartCountDown,
            CountDown,
            StartGame,
            StopGame,
            ForceStopGame,
            MoveLeft,
            MoveRight,
            MoveForward,
            SpeedUp,
            SpeedDown,
            StateUpdated
        };

        EventType eventType;

        explicit Event(EventType eventType, const std::string& message = "");
        Event(EventType eventType, int hikerIndex, const std::string& message = "");
        Event(EventType eventType, const std::shared_ptr<HikerModel>& hiker, const std::string& message = "");

        virtual std::string what();

        int getHikerIndex() const;

        double getHikerX() const;
        double getHikerY() const;
    };
}


#endif //TURBOHIKER_EVENT_H
