//
// Created by Casper De Smet on 22/12/2020.
//

#include "GameViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    void GameViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (onCountDown)
            target.draw(countDownText);
    }

    GameViewSFML::GameViewSFML()
    {
        font.loadFromFile("arial.ttf");

        countDownText = sf::Text(to_string(countDown), font);
        countDownText.setCharacterSize(300);
        countDownText.setStyle(sf::Text::Bold);
        countDownText.setFillColor(sf::Color(255, 205, 0));

        sf::FloatRect bounds = countDownText.getLocalBounds();
        countDownText.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        countDownText.setPosition(800, 800);
    }

//    void GameViewSFML::receiveGameEvent(const shared_ptr<turboHiker::GameEvent>& event)
//    {
//        switch (event->gameEventType)
//        {
//            case turboHiker::GameEvent::StartCountDown:
//                onCountDown = true;
//                break;
//            case turboHiker::GameEvent::CountDown:
//                countDown--;
//                countDownText.setString(to_string(countDown));
//                break;
//            case turboHiker::GameEvent::Start:
//                onCountDown = false;
//                break;
//            case turboHiker::GameEvent::Stop:
//                break;
//            case turboHiker::GameEvent::ForcedStop:
//                break;
//        }
//    }

    void GameViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {

            case turboHiker::Event::StartCountDown:
                onCountDown = true;
                break;
            case turboHiker::Event::CountDown:
                countDown--;
                countDownText.setString(to_string(countDown));
                break;
            case turboHiker::Event::StartGame:
                onCountDown = false;
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
                break;
        }
    }
}