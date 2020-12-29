//
// Created by Casper De Smet on 16/12/2020.
//

#include "WorldViewSFML.h"
#include "../Controller/World.h"

using namespace std;

namespace turboHikerSFML
{
    bool WorldViewSFML::showHitBoxes = false;

    WorldViewSFML::WorldViewSFML(int screenX, int screenY): WorldView(screenX, screenY), playerHikerIndex(0)
    {
        renderWindow = make_shared<sf::RenderWindow>(sf::VideoMode(screenX, screenY), "TurboHiker");
        drawTask = packaged_task<void()>(bind(&WorldViewSFML::drawer, this));
        drawFuture = drawTask.get_future();

        directionMap = {{sf::Keyboard::Left, turboHiker::Event::MoveLeft}, {sf::Keyboard::Right, turboHiker::Event::MoveRight}};
    }

    void WorldViewSFML::render()
    {
        cout << "This worldViewSFML is being rendered." << endl;

        thread(move(drawTask)).detach();
        while (renderWindow->isOpen())
        {
            sf::Event event{};
            while (renderWindow->pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        renderWindow->close();
                        world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::ForceStopGame, "Force the game to stop."));
                        break;
                    case sf::Event::MouseButtonPressed:
                        processClickEvent(event);
                        break;
                    case sf::Event::KeyPressed:
                        processKeyPressedEvent(event);
                        break;
                    case sf::Event::KeyReleased:
                        processKeyReleasedEvent(event);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    shared_ptr<turboHiker::HikerView> WorldViewSFML::constructHiker(int hikerIndex, turboHiker::World::HikerType hikerType, const weak_ptr<turboHiker::WorldView>& worldView)
    {
        shared_ptr<turboHiker::HikerView> hiker;
        switch (hikerType)
        {
            case turboHiker::World::PlayerHiker:
                hiker = make_shared<PlayerHikerViewSFML>(worldView, hikerIndex);
                playerHikerIndex = hikerIndex;
                break;
            case turboHiker::World::RacingHiker:
                hiker = make_shared<RacingHikerViewSFML>(worldView, hikerIndex);
                break;
        }
        hikers.emplace_back(hiker);
        return hiker;
    }

    void WorldViewSFML::constructLane(int laneIndex, const weak_ptr<turboHiker::WorldView>& worldView, const list<shared_ptr<turboHiker::HikerView>>& hikerList)
    {
        shared_ptr<turboHiker::LaneView> lane = make_shared<LaneViewSFML>(worldView, laneIndex, hikerList);
        lanes.emplace_back(lane);
        for (const std::shared_ptr<turboHiker::HikerView>& hiker: hikerList)
            hiker->setCurrentLane(lane);
    }

    void WorldViewSFML::constructGame()
    {
        game = make_shared<GameViewSFML>();
    }

    void WorldViewSFML::processClickEvent(const sf::Event& event)
    {
        sf::Vector2<int> position = sf::Mouse::getPosition(*renderWindow);
        for (const shared_ptr<turboHiker::HikerView>& baseHiker: hikers)
        {
            shared_ptr<HikerViewSFML> hiker = dynamic_pointer_cast<HikerViewSFML>(baseHiker);
            hiker->deselect();
            if (hiker->isClicked(position.x, position.y))
            {
                hiker->select();
//                selectedHiker = hiker;
            }
        }
        pair<double, double> worldPosition = turboHiker::Transformation::getInstance().screenToWorld(position.x, position.y);
        cout << "The screen was clicked at " << position.x << ", " << position.y << endl;
        cout << "This translates to " << worldPosition.first << ", " << worldPosition.second << endl;
    }

    void WorldViewSFML::processKeyPressedEvent(const sf::Event& event)
    {
        switch (event.key.code)
        {
//            case sf::Keyboard::Space:
//                world.lock()->raiseViewEvent(
//                        make_shared<turboHiker::HikerViewEvent>(selectedHiker->getIndex(), turboHiker::HikerEvent::StartMoving,
//                                                                "Hiker " + to_string(selectedHiker->getIndex()) + " starts moving."));
//                break;
            case sf::Keyboard::H:
                WorldViewSFML::showHitBoxes = !WorldViewSFML::showHitBoxes;
                break;
            case sf::Keyboard::Up:
                world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::SpeedUp, playerHikerIndex));
                break;
            case sf::Keyboard::Down:
                world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::SpeedDown, playerHikerIndex));
                break;
            case sf::Keyboard::Left:
            case sf::Keyboard::Right:
                arrowKeysState.pressKey(directionMap[event.key.code]);
                world.lock()->handleEvent(make_shared<turboHiker::Event>(directionMap[event.key.code], playerHikerIndex));
                break;
            default:
                break;
        }
    }

    void WorldViewSFML::processKeyReleasedEvent(const sf::Event& event)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Up:
            case sf::Keyboard::Down:
            case sf::Keyboard::Left:
            case sf::Keyboard::Right:
//                if (!arrowKeysState.keyPressed())
//                    world.lock()->raiseViewEvent(make_shared<turboHiker::HikerViewEvent>(playerHikerIndex, turboHiker::HikerEvent::StopMoving,
//                                                                                               turboHiker::HikerEvent::NoDirection, "The player hiker stops moving."));
                arrowKeysState.releaseKey(directionMap[event.key.code]);
                break;
            default:
                break;
        }
    }

//    void WorldViewSFML::receiveGameEvent(const shared_ptr<turboHiker::GameEvent>& event)
//    {
//        game->receiveGameEvent(event);
//        switch (event->gameEventType)
//        {
//            default:
//                break;
//        }
//    }

    void WorldViewSFML::drawer()
    {
        while (renderWindow->isOpen())
        {
            renderWindow->clear(sf::Color::White);
            for (const shared_ptr<turboHiker::LaneView>& lane: lanes)
                renderWindow->draw(*dynamic_pointer_cast<LaneViewSFML>(lane));
            for (const shared_ptr<turboHiker::HikerView>& hiker: hikers)
                renderWindow->draw(*dynamic_pointer_cast<HikerViewSFML>(hiker));
            renderWindow->draw(*dynamic_pointer_cast<GameViewSFML>(game));
            renderWindow->display();
        }
    }

    WorldViewSFML::~WorldViewSFML()
    {
        drawFuture.wait();
    }

    void WorldViewSFML::changeLane(int hikerIndex, turboHiker::Event::EventType eventType)
    {

    }

    void WorldViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::StartCountDown:
            case turboHiker::Event::CountDown:
            case turboHiker::Event::StartGame:
            case turboHiker::Event::StopGame:
            case turboHiker::Event::ForceStopGame:
                game->handleEvent(event);
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