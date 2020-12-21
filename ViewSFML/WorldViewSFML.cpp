//
// Created by Casper De Smet on 16/12/2020.
//

#include "WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    bool WorldViewSFML::showHitBoxes = false;

    WorldViewSFML::WorldViewSFML(): WorldView()
    {
        renderWindow = make_shared<sf::RenderWindow>(sf::VideoMode(1600, 1600), "TurboHiker");
    }

    void WorldViewSFML::render()
    {
        cout << "This worldViewSFML is being rendered." << endl;

        while (renderWindow->isOpen())
        {
            sf::Event event{};
            while (renderWindow->pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        renderWindow->close();
                        world.lock()->raiseGameEvent(make_shared<turboHiker::GameEvent>(turboHiker::GameEvent::ForcedStop, "Force the game to stop."));
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

            renderWindow->clear(sf::Color::White);
            for (const shared_ptr<turboHiker::LaneView>& lane: lanes)
                renderWindow->draw(*dynamic_pointer_cast<LaneViewSFML>(lane));
            for (const shared_ptr<turboHiker::HikerView>& hiker: hikers)
                renderWindow->draw(*dynamic_pointer_cast<HikerViewSFML>(hiker));
            renderWindow->display();
        }
    }

    shared_ptr<turboHiker::HikerView> WorldViewSFML::constructHiker(int hikerIndex, const weak_ptr<turboHiker::WorldView>& worldView)
    {
        shared_ptr<turboHiker::HikerView> hiker = make_shared<HikerViewSFML>(worldView, hikerIndex);
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

    void WorldViewSFML::processKeyPressedEvent(const sf::Event& event)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Space:
                world.lock()->raiseViewEvent(
                        make_shared<turboHiker::HikerViewEvent>(selectedHiker->getIndex(), turboHiker::HikerEvent::StartMoving,
                                                                        "Hiker " + to_string(selectedHiker->getIndex()) + " starts moving."));
                break;
            case sf::Keyboard::H:
                WorldViewSFML::showHitBoxes = !WorldViewSFML::showHitBoxes;
                break;
            case sf::Keyboard::Up:
                world.lock()->raiseViewEvent(make_shared<turboHiker::HikerViewEvent>(3, turboHiker::HikerEvent::StartMoving, "The player hiker starts moving."));
                break;
            default:
                break;
        }
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
                selectedHiker = hiker;
            }
        }
    }

    void WorldViewSFML::processKeyReleasedEvent(const sf::Event& event)
    {
        switch (event.key.code)
        {
            case sf::Keyboard::Up:
                world.lock()->raiseViewEvent(make_shared<turboHiker::HikerViewEvent>(3, turboHiker::HikerEvent::StopMoving, "The player hiker stops moving."));
                break;
            default:
                break;
        }
    }
}