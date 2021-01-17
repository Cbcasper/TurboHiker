//
// Created by Casper De Smet on 16/12/2020.
//

#ifndef TURBOHIKER_HIKERVIEWSFML_H
#define TURBOHIKER_HIKERVIEWSFML_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../LaneViewSFML.h"
#include "../../View/HikerView/HikerView.h"

namespace turboHikerSFML
{
    class WorldViewSFML;

    // Implementation of interface from turboHiker library and drawable from SFML, base class for all hiker views
    class HikerViewSFML: public sf::Drawable, virtual public turboHiker::HikerView
    {
    protected:
        // Current position
        float x;
        float y;

        // New position received from update
        float newX;
        float newY;

        // Texture for the sprite
        sf::Texture texture;
        sf::Sprite sprite;
        sf::RectangleShape hitBox;

        // Times the hiker has moved
        int moveCount;

        // Function to set sprite and hitbox, to be used by derived classes
        void setSprite();
        void setHitBox(float scaleX, float scaleY);

    public:
        HikerViewSFML();

        // Implementation of function from base class Drawable
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        // Implementation of functions from base class HikerView
        // This class is still abstract and not meant to be used as object,
        // so this is an abstract implementation for the derived hiker view classes
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override = 0;
        std::pair<float, float> getHitboxSize() const override;

        float getNewY() const;
        // Set the x and y to the newX and newY
        void acceptNewPosition();

        void incrementMoveCount();
    };
}


#endif //TURBOHIKER_HIKERVIEWSFML_H
