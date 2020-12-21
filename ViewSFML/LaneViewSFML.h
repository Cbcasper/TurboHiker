//
// Created by Casper De Smet on 17/12/2020.
//

#ifndef TURBOHIKER_LANEVIEWSFML_H
#define TURBOHIKER_LANEVIEWSFML_H

#include <SFML/Graphics.hpp>
#include "../View/LaneView.h"

namespace turboHikerSFML
{
    class LaneViewSFML: public turboHiker::LaneView, public sf::Drawable
    {
    private:
        sf::Texture texture;
        sf::RectangleShape rectangleShape;

    public:
        LaneViewSFML(const std::weak_ptr<turboHiker::WorldView>& world, int index, const std::list<std::shared_ptr<turboHiker::HikerView>>& hikers);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    };
}


#endif //TURBOHIKER_LANEVIEWSFML_H
