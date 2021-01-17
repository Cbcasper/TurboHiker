//
// Created by Casper De Smet on 17/12/2020.
//

#include "LaneViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    LaneViewSFML::LaneViewSFML(const weak_ptr<turboHiker::WorldView>& world, int index, const std::shared_ptr<turboHiker::HikerView>& hiker): LaneView(world, index, hiker), topY(0), bottomY(-1600)
    {
        // Load the texture
        texture.loadFromFile("cobblePathLanes.png");

        // Set parameters or both rectangles to be identical, except for the y-value
        topRectangle = sf::RectangleShape(sf::Vector2f(400, 1600));
        topRectangle.setTexture(&texture);
        topRectangle.setTextureRect(sf::IntRect(float(index) * 512, 0, 512, 2048));
        topRectangle.setPosition(float(index) * 400, float(topY));

        bottomRectangle = sf::RectangleShape(sf::Vector2f(400, 1600));
        bottomRectangle.setTexture(&texture);
        bottomRectangle.setTextureRect(sf::IntRect(float(index) * 512, 0, 512, 2048));
        bottomRectangle.setPosition(float(index) * 400, float(bottomY));
    }

    void LaneViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(topRectangle);
        target.draw(bottomRectangle);
    }

    void LaneViewSFML::scroll(double offset)
    {
        // Compute the new values and wrap them
        topY = wrap(topY + offset, 0, 1600);
        bottomY = wrap(bottomY + offset, -1600, 0);
        // Set the position of the rectangles to the new values
        topRectangle.setPosition(float(index) * 400, float(topY));
        bottomRectangle.setPosition(float(index) * 400, float(bottomY));
    }

    double LaneViewSFML::wrap(double value, int bottomBorder, int topBorder)
    {
        // Check if the value is outside of the given interval
        if (value > topBorder)
            // Set it inside the interval
            return bottomBorder + (value - topBorder);
        return value;
    }
}