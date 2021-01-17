//
// Created by Casper De Smet on 11/01/2021.
//

#ifndef TURBOHIKER_OBSTACLEVIEWSFML_H
#define TURBOHIKER_OBSTACLEVIEWSFML_H

#include <SFML/Graphics.hpp>
#include "../View/ObstacleView.h"

namespace turboHikerSFML
{
    class ObstacleViewSFML: public turboHiker::ObstacleView, public sf::Drawable
    {
    private:
        float x;
        float y;

        bool broken;

        // Textures for if its broken and intact
        sf::Texture intactTexture;
        sf::Texture brokenTexture;
        sf::Sprite sprite;
        sf::RectangleShape hitBox;

    public:
        ObstacleViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, const std::weak_ptr<turboHiker::LaneView>& currentLane, float x, float y);

        // Implementation of abstract function from interface Drawable
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // Implementations of abstract functions of interface ObstacleView
        std::pair<float, float> getHitboxSize() override;
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_OBSTACLEVIEWSFML_H
