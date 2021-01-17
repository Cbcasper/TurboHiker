//
// Created by Casper De Smet on 16/12/2020.
//

#include "WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    bool WorldViewSFML::showHitBoxes = false;

    WorldViewSFML::WorldViewSFML(const weak_ptr<turboHiker::World>& world, double screenX, double screenY): WorldView(world, screenX, screenY), playerHiker(nullptr), shiftKeysPressed(), started(false)
    {
        // Make the renderWindow with the given dimensions and an extra 200 pixel
        renderWindow = make_shared<sf::RenderWindow>(sf::VideoMode(screenX, screenY + 200), "TurboHiker", sf::Style::Titlebar | sf::Style::Close);

        directionMap = {{sf::Keyboard::Left, turboHiker::Event::MoveLeft}, {sf::Keyboard::Right, turboHiker::Event::MoveRight}};
    }

    void WorldViewSFML::render()
    {
        // Start the drawing
        bool duringPreparation;
        while (renderWindow->isOpen())
        {
            sf::Event event{};
            while (renderWindow->pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        // When the window is closed the game should be forced to stop
                        renderWindow->close();
                        world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::ForceStopGame, "Force the game to stop."));
                        break;
                    case sf::Event::KeyPressed:
                        processKeyPressedEvent(event);
                        break;
                    case sf::Event::KeyReleased:
                        processKeyReleasedEvent(event);
                        break;
                    case sf::Event::TextEntered:
                        dynamic_pointer_cast<GameViewSFML>(game)->enterText(event.text.unicode);
                        break;
                    default:
                        break;
                }
            }

            duringPreparation = dynamic_pointer_cast<GameViewSFML>(game)->duringPreparation;
            renderWindow->clear(sf::Color::White);
            if (!duringPreparation)
                for (const shared_ptr<turboHiker::LaneView>& lane: lanes)
                    renderWindow->draw(*dynamic_pointer_cast<LaneViewSFML>(lane));
            renderWindow->draw(*dynamic_pointer_cast<GameViewSFML>(game));
            if (!duringPreparation)
                for (const shared_ptr<turboHiker::ObstacleView>& obstacle: obstacles)
                    renderWindow->draw(*dynamic_pointer_cast<ObstacleViewSFML>(obstacle));
            if (!duringPreparation)
                for (const shared_ptr<turboHiker::HikerView>& hiker: hikers)
                    renderWindow->draw(*dynamic_pointer_cast<HikerViewSFML>(hiker));
            renderWindow->draw(*dynamic_pointer_cast<ScoringViewSFML>(scoring));
            renderWindow->display();
        }
    }

    void WorldViewSFML::constructGame(const weak_ptr<turboHiker::WorldView>& worldView, double finishX, double finishY)
    {
        game = make_shared<GameViewSFML>(worldView);
        game->setFinishLinePosition(finishX, finishY);
    }

    void WorldViewSFML::constructScoring(const weak_ptr<turboHiker::WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores)
    {
        scoring = make_shared<ScoringViewSFML>(worldView, highScores);
    }

    void WorldViewSFML::processKeyPressedEvent(const sf::Event& event)
    {
        // If the game hasn't started, only accept Enter
        if (!started && !(event.key.code == sf::Keyboard::Return)) return;
        switch (event.key.code)
        {
            case sf::Keyboard::H:
                WorldViewSFML::showHitBoxes = !WorldViewSFML::showHitBoxes;
                break;
            // Raise the right event for the key entered, to move the hiker
            case sf::Keyboard::Up:
                world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::SpeedUp, playerHiker->getIndex()));
                break;
            case sf::Keyboard::Down:
                world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::SpeedDown, playerHiker->getIndex()));
                break;
            case sf::Keyboard::Left:
            case sf::Keyboard::Right:
                world.lock()->handleEvent(
                        make_shared<turboHiker::Event>(directionMap[event.key.code], playerHiker->getIndex()));
                break;
            // Halt the player when shift is pressed
            case sf::Keyboard::RShift:
            case sf::Keyboard::LShift:
                shiftKeysPressed.pressKey(event.key.code);
                world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::HaltHiker, playerHiker->getIndex()));
                break;
            case sf::Keyboard::Return:
                // Let the game accept the name
                dynamic_pointer_cast<GameViewSFML>(game)->acceptName();
                break;
            default:
                break;
        }
    }

    void WorldViewSFML::processKeyReleasedEvent(const sf::Event& event)
    {
        // If the game hasn't started, only accept Enter
        if (!started && !(event.key.code == sf::Keyboard::Return)) return;
        switch (event.key.code)
        {
            // Release a key and if none are pressed, raise the LetGoHiker event
            case sf::Keyboard::RShift:
            case sf::Keyboard::LShift:
                shiftKeysPressed.releaseKey(event.key.code);
                if (!shiftKeysPressed.keyPressed())
                    world.lock()->handleEvent(make_shared<turboHiker::Event>(turboHiker::Event::LetGoHiker, started && playerHiker->getIndex()));
                break;
            default:
                break;
        }
    }

    void WorldViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            // Pass event to game
            case turboHiker::Event::StartCountDown:
            case turboHiker::Event::CountDown:
                game->handleEvent(event);
                break;
            // Pass event to game
            case turboHiker::Event::StartGame:
                started = true;
            case turboHiker::Event::StopGame:
            case turboHiker::Event::ForceStopGame:
                game->handleEvent(event);
                scoring->handleEvent(event);
                break;
            // Pass event to scoring
            case turboHiker::Event::Tick:
                scoring->handleEvent(event);
                break;
            case turboHiker::Event::HikerStateUpdated:
                handleHikerStateUpdate(event);
                break;
            case turboHiker::Event::ObstacleStateUpdated:
                // Pass event to obstacle
                obstacles[event->getObstacleIndex()]->handleEvent(event);
                break;
            default:
                break;
        }
    }

    void WorldViewSFML::handleHikerStateUpdate(const shared_ptr<turboHiker::Event>& event)
    {
        // Let the hiker handle the event
        hikers[event->getHikerIndex()]->handleEvent(event);
        if (started &&
            playerHiker && event->getHikerIndex() == playerHiker->getIndex() &&
            playerHiker->getNewY() < float(screenY) / 2)
        {
            // If the newX and newY of the player hiker is above a certain threshold, scroll the screen down
            turboHiker::Transformation::getInstance().moveViewport(playerHiker->getYOffset());
            for (const shared_ptr<turboHiker::LaneView>& lane: lanes)
                dynamic_pointer_cast<LaneViewSFML>(lane)->scroll(playerHiker->getYOffset());
            game->scroll(playerHiker->getYOffset());
            return;
        }
        // Let the hiker accept his new position
        dynamic_pointer_cast<HikerViewSFML>(hikers[event->getHikerIndex()])->acceptNewPosition();
    }

    void WorldViewSFML::raiseEvent(const shared_ptr<turboHiker::Event>& event)
    {
        world.lock()->handleEvent(event);
    }

    void WorldViewSFML::setPlayerHiker(const shared_ptr<turboHiker::HikerView>& hiker)
    {
        playerHiker = dynamic_pointer_cast<PlayerHikerViewSFML>(hiker);
    }
}
