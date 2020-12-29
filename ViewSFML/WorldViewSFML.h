//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEWSFML_H
#define TURBOHIKER_WORLDVIEWSFML_H

#include <iostream>
#include <thread>
#include <future>
#include <SFML/Graphics.hpp>
#include "../View/WorldView.h"
#include "../Controller/World.h"
#include "HikerViewSFML/PlayerHikerViewSFML.h"
#include "HikerViewSFML/RacingHikerViewSFML.h"
#include "LaneViewSFML.h"
#include "GameViewSFML.h"
#include "../Utilities/Transformation.h"
#include "ViewSFMLUtilities/ArrowKeysState.h"

namespace turboHikerSFML
{
    class WorldViewSFML: public turboHiker::WorldView
    {
    private:
        std::shared_ptr<sf::RenderWindow> renderWindow;
        std::shared_ptr<turboHiker::HikerView> selectedHiker;

        std::packaged_task<void()> drawTask;
        std::future<void> drawFuture;

        int playerHikerIndex;
        ArrowKeysState arrowKeysState;

        std::map<sf::Keyboard::Key, turboHiker::Event::EventType> directionMap;

        void drawer();

    public:
        static bool showHitBoxes;

        WorldViewSFML(int screenX, int screenY);
        virtual ~WorldViewSFML();

        std::shared_ptr<turboHiker::HikerView> constructHiker(int hikerIndex, turboHiker::World::HikerType hikerType, const std::weak_ptr<turboHiker::WorldView>& worldView) override;
        void constructLane(int laneIndex, const std::weak_ptr<turboHiker::WorldView>& worldView, const std::list<std::shared_ptr<turboHiker::HikerView>>& hikerList) override;
        void constructGame() override;

        void processKeyPressedEvent(const sf::Event& event);
        void processKeyReleasedEvent(const sf::Event& event);
        void processClickEvent(const sf::Event& event);

        void render() override;

//        void receiveGameEvent(const std::shared_ptr<turboHiker::GameEvent>& event) override;
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;

        void changeLane(int hikerIndex, turboHiker::Event::EventType eventType) override;
    };
}


#endif //TURBOHIKER_WORLDVIEWSFML_H
