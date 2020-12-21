//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEWSFML_H
#define TURBOHIKER_WORLDVIEWSFML_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../View/WorldView.h"
#include "../Controller/World.h"
#include "HikerViewSFML.h"
#include "LaneViewSFML.h"

namespace turboHikerSFML
{
    class WorldViewSFML: public turboHiker::WorldView
    {
    private:
        std::shared_ptr<sf::RenderWindow> renderWindow;
        std::shared_ptr<turboHiker::HikerView> selectedHiker;

    public:
        static bool showHitBoxes;

        WorldViewSFML();

        std::shared_ptr<turboHiker::HikerView> constructHiker(int hikerIndex, const std::weak_ptr<turboHiker::WorldView>& worldView) override;
        void constructLane(int laneIndex, const std::weak_ptr<turboHiker::WorldView>& worldView, const std::list<std::shared_ptr<turboHiker::HikerView>>& hikerList) override;

        void processKeyPressedEvent(const sf::Event& event);
        void processKeyReleasedEvent(const sf::Event& event);
        void processClickEvent(const sf::Event& event);

        void render() override;
    };
}


#endif //TURBOHIKER_WORLDVIEWSFML_H
