//
// Created by Casper De Smet on 11/01/2021.
//

#include "ObstacleViewSFML.h"
#include "WorldViewSFML.h"
#include "../Model/ObstacleModel.h"

using namespace std;

namespace turboHikerSFML
{
    ObstacleViewSFML::ObstacleViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, const weak_ptr<turboHiker::LaneView>& currentLane, float x, float y):
                                       ObstacleView(worldView, currentLane), x(x), y(y)
    {
        // Load textures
        intactTexture.loadFromFile("barrel 1.png");
        brokenTexture.loadFromFile("barrel 6.png");

        // Set parameters of sprite
        float spriteX = intactTexture.getSize().x;
        float spriteY = intactTexture.getSize().y;
        sprite.setTexture(intactTexture);
        sprite.setTextureRect(sf::IntRect(0, 0, spriteX, spriteY));
        sprite.setColor(sf::Color::White);
        sprite.setOrigin(spriteX / 2.0f, spriteY / 2.0f);
        sprite.setPosition(x, y);
        sprite.setScale(0.85, 0.85);

        // Set parameters of hitbox
        double scaleX = 0.5;
        double scaleY = 0.6;
        auto width = float(sprite.getLocalBounds().width * scaleX);
        auto height = float(sprite.getLocalBounds().height * scaleY);
        hitBox.setSize(sf::Vector2f(width, height));
        hitBox.setOrigin(width / 2.0f, height / 2.0f);
        hitBox.setPosition(x, y);
        hitBox.setFillColor(sf::Color::Transparent);
        hitBox.setOutlineThickness(3);
        hitBox.setOutlineColor(sf::Color::White);
    }

    pair<float, float> ObstacleViewSFML::getHitboxSize()
    {
        return {hitBox.getSize().x, hitBox.getSize().y};
    }

    void ObstacleViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
        if (WorldViewSFML::showHitBoxes)
            target.draw(hitBox);
    }

    void ObstacleViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::ObstacleStateUpdated:
                // Accept the new position and update the hitbox and sprite
                tie(x, y) = turboHiker::Transformation::getInstance().worldToScreen(event->getObstacleX(), event->getObstacleY());
                sprite.setPosition(x, y);
                hitBox.setPosition(x, y);
                // Accept the new broken state and set the texture accordingly
                if (!broken && event->getObstacle()->isBroken())
                {
                    broken = true;
                    sprite.setTexture(brokenTexture);
                }
                break;
            default:
                break;
        }
    }
}