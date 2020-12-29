//
// Created by Casper De Smet on 21/12/2020.
//

#include "RacingHikerViewSFML.h"

using namespace std;

namespace turboHikerSFML
{

    RacingHikerViewSFML::RacingHikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex) :
            RacingHikerView(worldView, hikerIndex), HikerView(worldView, hikerIndex)
    {
        texture.loadFromFile("dash.png");

        setSprite();
        sprite.setScale(0.6, 0.6);

        setHitBox(0.40);
    }

    void RacingHikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::StartCountDown:
                break;
            case turboHiker::Event::CountDown:
                break;
            case turboHiker::Event::StartGame:
                break;
            case turboHiker::Event::StopGame:
                break;
            case turboHiker::Event::ForceStopGame:
                break;
            case turboHiker::Event::MoveLeft:
                break;
            case turboHiker::Event::MoveRight:
                break;
            case turboHiker::Event::MoveForward:
                break;
            case turboHiker::Event::SpeedUp:
                break;
            case turboHiker::Event::SpeedDown:
                break;
            case turboHiker::Event::StateUpdated:
                tie(x, y) = turboHiker::Transformation::getInstance().worldToScreen(event->getHikerX(),
                                                                                           event->getHikerY());
                sprite.setPosition(x, y);
                hitBox.setPosition(x, y);
                break;
        }
    }

//    void RacingHikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
//    {
//        stringstream message;
//        message << "HikerView " << hikerIndex << " received an event: " << event->what() << endl;
//        cout << message.str();
//        switch (event->eventType)
//        {
//            case turboHiker::Event::HikerModelEvent:
//            {
//                shared_ptr<turboHiker::HikerModelEvent> modelHikerEvent = dynamic_pointer_cast<turboHiker::HikerModelEvent>(event);
//                if (modelHikerEvent->hikerEventType == turboHiker::HikerEvent::StateUpdated)
//                {
//                    tie(x, y) = turboHiker::Transformation::getInstance().worldToScreen(modelHikerEvent->getHikerX(),
//                                                                                               modelHikerEvent->getHikerY());
//                    sprite.setPosition(x, y);
//                    hitBox.setPosition(x, y);
//                }
//            }
//                break;
//            default:
//                break;
//        }
//    }
}