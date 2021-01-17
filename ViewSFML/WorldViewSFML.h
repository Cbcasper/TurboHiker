//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEWSFML_H
#define TURBOHIKER_WORLDVIEWSFML_H

#include <iostream>
#include <thread>
#include <future>
#include <SFML/Graphics.hpp>
#include "LaneViewSFML.h"
#include "GameViewSFML.h"
#include "ScoringViewSFML.h"
#include "ObstacleViewSFML.h"
#include "ViewSFMLUtilities/ShiftKeysPressed.h"
#include "HikerViewSFML/PlayerHikerViewSFML.h"
#include "HikerViewSFML/RacingHikerViewSFML.h"
#include "HikerViewSFML/StandingHikerViewSFML.h"
#include "HikerViewSFML/AdversaryHikerViewSFML.h"
#include "../View/WorldView.h"
#include "../Controller/World.h"
#include "../Utilities/Transformation.h"

namespace turboHikerSFML
{
    // Implementation of interface WorldView from turboHiker library
    class WorldViewSFML: public turboHiker::WorldView
    {
    private:
        // Whether the game has started
        bool started;

        // Window the game will be displayed on
        std::shared_ptr<sf::RenderWindow> renderWindow;

        // Store the playerHiker separately for easy access
        std::shared_ptr<PlayerHikerViewSFML> playerHiker;

        // Keep the state of the shift keys
        ShiftKeysPressed shiftKeysPressed;

        // Map the keys to turboHiker events
        std::map<sf::Keyboard::Key, turboHiker::Event::EventType> directionMap;

    public:
        static bool showHitBoxes;

        WorldViewSFML(const std::weak_ptr<turboHiker::World>& world, double screenX, double screenY);
        virtual ~WorldViewSFML() = default;

        void constructGame(const std::weak_ptr<turboHiker::WorldView>& worldView, double finishX, double finishY) override;
        void constructScoring(const std::weak_ptr<turboHiker::WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores) override;

        // Process sf::Events
        void processKeyPressedEvent(const sf::Event& event);
        void processKeyReleasedEvent(const sf::Event& event);

        // Implementations of abstract functions of interface WorldView
        void render() override;
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;

        void setPlayerHiker(const std::shared_ptr<turboHiker::HikerView>& hiker) override;

        // Pass event through
        void raiseEvent(const std::shared_ptr<turboHiker::Event>& event);

        void handleHikerStateUpdate(const std::shared_ptr<turboHiker::Event>& event);
    };
}


#endif //TURBOHIKER_WORLDVIEWSFML_H
