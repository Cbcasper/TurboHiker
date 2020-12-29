//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEWSFML_H
#define TURBOHIKER_HIKERVIEWSFML_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../View/HikerView/HikerView.h"
#include "../LaneViewSFML.h"

namespace turboHikerSFML
{
    class WorldViewSFML;

    class HikerViewSFML: public sf::Drawable, virtual public turboHiker::HikerView
    {
    protected:
        float x;
        float y;

        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape hitBox;

        bool selected;

        void setSprite();
        void setHitBox(float scale);

    public:
        HikerViewSFML();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        bool isClicked(double x, double y);
        void select();
        void deselect();
    };
}


#endif //TURBOHIKER_HIKERVIEWSFML_H
