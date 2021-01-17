//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_EVENT_H
#define TURBOHIKER_EVENT_H

#include <string>
#include <chrono>
#include <memory>

namespace turboHiker
{
    class HikerModel;
    class ObstacleModel;

    class Event
    {
    protected:
        // Optional message
        std::string message;

        // The index and optionally model of the relevant hiker
        int hikerIndex{};
        std::shared_ptr<HikerModel> hiker = nullptr;

        // Index of the other hiker in case of collision
        int otherHikerIndex{};

        // The index and optionally model of the relevant obstacle
        int obstacleIndex{};
        std::shared_ptr<ObstacleModel> obstacle = nullptr;

        std::string playerName;

        std::chrono::milliseconds gameLength;

    public:
        enum EventType
        {
            // Members defined              |hikerIndex      |hiker       |obstacleIndex        |obstacle       |otherHikerIndex    |playerName
            StartCountDown,               //|                |            |                     |               |                   |
            CountDown,                    //|                |            |                     |               |                   |
            StartGame,                    //|                |            |                     |               |                   |
            StopGame,                     //|                |            |                     |               |                   |
            ForceStopGame,                //|                |            |                     |               |                   |
            GamePrepared,                 //|                |            |                     |               |                   |defined
            HikerFinished,                //|defined         |            |                     |               |                   |
            Tick,                         //|                |            |                     |               |                   |
            MoveLeft,                     //|defined         |            |                     |               |                   |
            MoveRight,                    //|defined         |            |                     |               |                   |
            MoveForward,                  //|defined         |            |                     |               |                   |
            MoveBackward,                 //|defined         |            |                     |               |                   |
            StartMoving,                  //|defined         |            |                     |               |                   |
            StopMoving,                   //|defined         |            |                     |               |                   |
            Jump,                         //|defined         |            |                     |               |                   |
            HaltHiker,                    //|defined         |            |                     |               |                   |
            LetGoHiker,                   //|defined         |            |                     |               |                   |
            SpeedUp,                      //|defined         |            |                     |               |                   |
            SpeedDown,                    //|defined         |            |                     |               |                   |
            HikerStateUpdated,            //|defined         |defined     |                     |               |                   |
            ObstacleStateUpdated,         //|                |            |defined              |defined        |                   |
            RequestHikerHitboxSize,       //|defined         |            |                     |               |                   |
            RequestObstacleHitBoxSize,    //|                |            |defined              |               |                   |
            CollisionWithHiker,           //|defined         |            |                     |               |defined            |
            CollisionWithObstacle,        //|defined         |            |defined              |               |                   |
        };

        EventType eventType;

        // Event without extra information
        explicit Event(EventType eventType);
        // Event about hiker or obstacle with index
        Event(EventType eventType, int index, const std::string& message = "");
        // Event about hiker with the model given for state
        Event(EventType eventType, const std::shared_ptr<HikerModel>& hiker, const std::string& message = "");
        // Event about obstacle with the model given for state
        Event(EventType eventType, const std::shared_ptr<ObstacleModel>& obstacle, const std::string& message = "");
        // Event about collision between hiker and obstacle/hiker
        Event(EventType eventType, int hikerIndex, int otherObjectIndex, const std::string& message = "");
        // Event for when the game has started and the name of the player is passed on
        Event(EventType eventType, const std::string& playerName, const std::string& message = "");
        // Event for ending the game, with the length of the game
        Event(EventType eventType, const std::chrono::milliseconds& gameLength, const std::string& message = "");

        // Returns the message
        std::string what();

        int getHikerIndex() const;
        int getObstacleIndex() const;
        int getOtherHikerIndex() const;

        double getHikerX() const;
        double getHikerY() const;

        double getObstacleX() const;
        double getObstacleY() const;

        const std::shared_ptr<ObstacleModel>& getObstacle() const;

        const std::string& getPlayerName() const;

        const std::chrono::milliseconds& getGameLength() const;
    };
}


#endif //TURBOHIKER_EVENT_H
