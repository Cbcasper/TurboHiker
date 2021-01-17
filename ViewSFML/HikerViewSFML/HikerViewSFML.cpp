//
// Created by Casper De Smet on 16/12/2020.
//

#include "HikerViewSFML.h"
#include "../WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    HikerViewSFML::HikerViewSFML(): x(0), y(0), newX(0), newY(0), moveCount(0)
    {}

    void HikerViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Draw the sprite and optionally the hitbox
        target.draw(sprite);
        if (WorldViewSFML::showHitBoxes)
            target.draw(hitBox);
    }

    void HikerViewSFML::setSprite()
    {
        // Set the parameters of the sprite
        float spriteX = texture.getSize().x;
        float spriteY = texture.getSize().y;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
        sprite.setColor(sf::Color::White);
        sprite.setOrigin(spriteX / 2.0f, spriteY / 2.0f);
        sprite.setPosition(x, y);
    }

    void HikerViewSFML::setHitBox(float scaleX, float scaleY)
    {
        // Set the parameters of the hitbox, to be a little bit smaller than the sprite
        auto width = float(sprite.getLocalBounds().width * scaleX);
        auto height = float(sprite.getLocalBounds().height * scaleY);
        hitBox.setSize(sf::Vector2f(width, height));
        hitBox.setOrigin(width / 2.0f, height / 2.0f);
        hitBox.setPosition(x, y);
        hitBox.setFillColor(sf::Color::Transparent);
        hitBox.setOutlineThickness(3);
        hitBox.setOutlineColor(sf::Color::White);
    }

    pair<float, float> HikerViewSFML::getHitboxSize() const
    {
        return {hitBox.getSize().x, hitBox.getSize().y};
    }

    void HikerViewSFML::acceptNewPosition()
    {
        // Set x and y and update the sprite and hitbox
        x = newX;
        y = newY;
        sprite.setPosition(x, y);
        hitBox.setPosition(x, y);
    }

    float HikerViewSFML::getNewY() const
    {
        return newY;
    }

    void HikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::HikerStateUpdated:
                // Transform the x and y of the hikerModel and store it in newX and newY
                tie(newX, newY) = turboHiker::Transformation::getInstance().worldToScreen(event->getHikerX(),
                                                                                                event->getHikerY());
                incrementMoveCount();
                break;
            default:
                break;
        }
    }

    void HikerViewSFML::incrementMoveCount()
    {
        // Increment the move count and wrap it if it becomes too big
        if (++moveCount == 250)
            moveCount = 0;
    }
}