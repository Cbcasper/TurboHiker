//
// Created by Casper De Smet on 17/12/2020.
//

#include "LaneViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    LaneViewSFML::LaneViewSFML(const weak_ptr<turboHiker::WorldView>& world, int index, const std::list<std::shared_ptr<turboHiker::HikerView>>& hikers) : LaneView(world, index, hikers)
    {
        texture.loadFromFile("grassTexture.jpg");
        rectangleShape = sf::RectangleShape(sf::Vector2f(400, 1600));
        rectangleShape.setTexture(&texture);
        rectangleShape.setTextureRect(sf::IntRect(float(index) * 600 + 900, 200, 600, 2400));
        rectangleShape.setPosition(float(index) * 400, 0);
    }

    void LaneViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectangleShape);
    }
}