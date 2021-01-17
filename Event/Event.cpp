//
// Created by Casper De Smet on 11/12/2020.
//

#include "Event.h"
#include "../Model/HikerModel/HikerModel.h"
#include "../Model/ObstacleModel.h"

using namespace std;

namespace turboHiker
{
    Event::Event(EventType eventType): message(string()), eventType(eventType)
    {}

    Event::Event(Event::EventType eventType, int index, const std::string& message): eventType(eventType), message(message)
    {

        switch (eventType)
        {
            case MoveLeft:
            case MoveRight:
            case MoveForward:
            case MoveBackward:
            case StartMoving:
            case StopMoving:
            case Jump:
            case HaltHiker:
            case LetGoHiker:
            case SpeedUp:
            case SpeedDown:
            case HikerStateUpdated:
            case RequestHikerHitboxSize:
            case HikerFinished:
                hikerIndex = index;
                break;
            case RequestObstacleHitBoxSize:
            case ObstacleStateUpdated:
                obstacleIndex = index;
                break;
            default:
                break;
        }
    }

    Event::Event(EventType eventType, const shared_ptr<HikerModel>& hiker, const std::string& message): eventType(eventType), hiker(hiker), message(message), hikerIndex(hiker->getIndex())
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

    int Event::getObstacleIndex() const
    {
        return obstacleIndex;
    }

    Event::Event(Event::EventType eventType, int hikerIndex, int otherObjectIndex, const string& message): eventType(eventType), message(message), hikerIndex(hikerIndex)
    {
        switch (eventType)
        {
            case CollisionWithHiker:
                otherHikerIndex = otherObjectIndex;
                break;
            case CollisionWithObstacle:
                obstacleIndex = otherObjectIndex;
            default:
                break;
        }
    }

    Event::Event(Event::EventType eventType, const shared_ptr<ObstacleModel>& obstacle, const string& message): eventType(eventType), message(message), obstacleIndex(obstacle->getIndex()), obstacle(obstacle)
    {}

    double Event::getObstacleX() const
    {
        return obstacle->getX();
    }

    double Event::getObstacleY() const
    {
        return obstacle->getY();
    }

    const std::shared_ptr<ObstacleModel>& Event::getObstacle() const
    {
        return obstacle;
    }

    Event::Event(Event::EventType eventType, const string& playerName, const string& message): eventType(eventType), message(message), playerName(playerName)
    {

    }

    Event::Event(Event::EventType eventType, const chrono::milliseconds& gameLength, const string& message): eventType(eventType), message(message), gameLength(gameLength)
    {

    }

    const chrono::milliseconds& Event::getGameLength() const
    {
        return gameLength;
    }

    const string& Event::getPlayerName() const
    {
        return playerName;
    }

    int Event::getOtherHikerIndex() const
    {
        return otherHikerIndex;
    }
}