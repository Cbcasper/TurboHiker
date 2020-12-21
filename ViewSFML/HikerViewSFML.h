//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEWSFML_H
#define TURBOHIKER_HIKERVIEWSFML_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../View/HikerView.h"
#include "LaneViewSFML.h"

namespace turboHikerSFML
{
    class WorldViewSFML;

    class HikerViewSFML: public turboHiker::HikerView, public sf::Drawable
    {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape hitBox;

        bool selected;

    public:
        HikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex);
        void receiveEvent(const std::shared_ptr<turboHiker::ModelEvent>& event) override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        bool isClicked(double x, double y);
        void select();
        void deselect();
    };
}


#endif //TURBOHIKER_HIKERVIEWSFML_H
