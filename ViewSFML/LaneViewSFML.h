//
// Created by Casper De Smet on 17/12/2020.
//

#ifndef TURBOHIKER_LANEVIEWSFML_H
#define TURBOHIKER_LANEVIEWSFML_H

#include <SFML/Graphics.hpp>
#include "../View/LaneView.h"

namespace turboHikerSFML
{
    // Implementation of interface LaneView from turboHiker library and interface Drawable from SFML
    class LaneViewSFML: public turboHiker::LaneView, public sf::Drawable
    {
    private:
        // Texture for the background
        sf::Texture texture;

        // Two rectangles to create a continuous scrolling background
        double topY;
        sf::RectangleShape topRectangle;
        double bottomY;
        sf::RectangleShape bottomRectangle;

    public:
        LaneViewSFML(const std::weak_ptr<turboHiker::WorldView>& world, int index, const std::shared_ptr<turboHiker::HikerView>& hiker);

        // Implementation of abstract function from interface Drawable
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // Move the background by a given offset
        void scroll(double offset);
        // Make sure the given value is in the given interval
        static double wrap(double value, int bottomBorder, int topBorder);
    };
}


#endif //TURBOHIKER_LANEVIEWSFML_H
