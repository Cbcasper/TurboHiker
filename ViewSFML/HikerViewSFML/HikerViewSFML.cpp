//
// Created by Casper De Smet on 16/12/2020.
//

#include "HikerViewSFML.h"
#include "../WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    HikerViewSFML::HikerViewSFML(): selected(false), x(0), y(0)
    {

    }

    void HikerViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
        if (WorldViewSFML::showHitBoxes)
            target.draw(hitBox);
    }

    bool HikerViewSFML::isClicked(double x, double y)
    {
        return hitBox.getGlobalBounds().contains(x, y);
    }

    void HikerViewSFML::select()
    {
        selected = true;
        hitBox.setOutlineColor(sf::Color::Red);
    }

    void HikerViewSFML::deselect()
    {
        selected = false;
        hitBox.setOutlineColor(sf::Color::White);
    }

    void HikerViewSFML::setSprite()
    {
        float spriteX = texture.getSize().x;
        float spriteY = texture.getSize().y;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
        sprite.setColor(sf::Color::White);
        sprite.setOrigin(spriteX / 2.0f, spriteY / 2.0f);
        sprite.setPosition(x, y);
    }

    void HikerViewSFML::setHitBox(float scale)
    {
        auto width = float(sprite.getTextureRect().width * scale);
        auto height = float(sprite.getTextureRect().height * scale);
        hitBox.setSize(sf::Vector2f(width, height));
        hitBox.setOrigin(width / 2.0f, height / 2.0f);
        hitBox.setPosition(x, y);
        hitBox.setFillColor(sf::Color::Transparent);
        hitBox.setOutlineThickness(3);
        hitBox.setOutlineColor(sf::Color::White);
    }
}