//
// Created by Casper De Smet on 13/12/2020.
//

#include <sstream>
#include "HikerModel.h"
#include "../WorldModel.h"

using namespace std;

namespace turboHiker
{
    HikerModel::HikerModel(const weak_ptr<WorldModel>& worldModel, int hikerIndex): worldModel(worldModel), hikerIndex(hikerIndex)
    {
        cout << "HikerModel " << hikerIndex << " is being constructed." << endl;
        y = worldModel.lock()->getWorldY() - 30;
        worldModel.lock()->raiseEvent(make_shared<Event>(Event::StateUpdated, make_shared<HikerModel>(*this), "The state of HikerModel " + to_string(hikerIndex) + " is getting updated."));
    }

    void HikerModel::handleEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::StartCountDown:
                break;
            case Event::CountDown:
                break;
            case Event::StartGame:
                break;
            case Event::StopGame:
                break;
            case Event::ForceStopGame:
                break;
            case Event::MoveLeft:
                x -= 50;
                break;
            case Event::MoveRight:
                x += 50;
                break;
            case Event::MoveForward:
                y -= 0.05;
                break;
            case Event::SpeedUp:
                break;
            case Event::SpeedDown:
                break;
            case Event::StateUpdated:
                break;
        }
    }

//    void HikerModel::handleEvent(const shared_ptr<Event>& event)
//    {
//        stringstream message;
//        message << "HikerModel " << hikerIndex << " received an event: " << event->what() << endl;
//        cout << message.str();
//        switch (event->eventType)
//        {
//            case Event::HikerControllerEvent:
//                processHikerEvent(dynamic_pointer_cast<HikerEvent>(event));
//                worldModel.lock()->raiseEvent(
//                        make_shared<HikerModelEvent>(shared_from_this(), HikerEvent::StateUpdated, HikerEvent::NoDirection,
//                                                            "The state of hikerModel " + to_string(hikerIndex) + " was updated."));
//            default:
//                break;
//        }
//    }

    void HikerModel::setCurrentLane(const weak_ptr<LaneModel>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
    }

    void HikerModel::initializeCurrentLane(const weak_ptr<LaneModel>& givenCurrentLane)
    {
        currentLane = givenCurrentLane;
        double laneWidth = worldModel.lock()->getWorldX() / 4;
        x = (laneWidth * currentLane.lock()->getLaneIndex()) + (laneWidth / 2);
    }

    std::string HikerModel::toString() const
    {
        stringstream output;
        output << "Hiker " << hikerIndex << " is at " << x << ", " << y;
        return output.str();
    }

    double HikerModel::getX() const
    {
        return x;
    }

    double HikerModel::getY() const
    {
        return y;
    }

    int HikerModel::getIndex() const
    {
        return hikerIndex;
    }

//    void HikerModel::processHikerEvent(const shared_ptr<HikerEvent>& event)
//    {
//        switch (event->hikerEventType)
//        {
//            case HikerEvent::Move:
//            {
//                switch (event->direction)
//                {
//                    case HikerEvent::Forward:       y -= 0.05;  break;
//                    case HikerEvent::Left:          x -= 50;    break;
//                    case HikerEvent::Right:         x += 50;    break;
//                    default:                                    break;
//                }
//            }
//                break;
//            default:
//                break;
//        }
//    }

    int HikerModel::getLaneIndex() const
    {
        return currentLane.lock()->getLaneIndex();
    }
}