//
// Created by Casper De Smet on 16/12/2020.
//

#include "HikerViewSFML.h"
#include "../ViewSFML/WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    HikerViewSFML::HikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex): HikerView(worldView, hikerIndex)
    {
        texture.loadFromFile("dash.png");

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 409, 652));
        sprite.setColor(sf::Color::White);
        sprite.setOrigin(204.5, 326);
        sprite.setPosition(x, y);
        sprite.setScale(0.6, 0.6);

        auto width = float(sprite.getTextureRect().width * 0.40);
        auto height = float(sprite.getTextureRect().height * 0.45);
        hitBox.setSize(sf::Vector2f(width, height));
        hitBox.setOrigin(width / 2, height / 2);
        hitBox.setPosition(x, y);
        hitBox.setFillColor(sf::Color::Transparent);
        hitBox.setOutlineThickness(3);
        hitBox.setOutlineColor(sf::Color::White);
    }

    void HikerViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite);
        if (WorldViewSFML::showHitBoxes)
            target.draw(hitBox);
    }

    void HikerViewSFML::receiveEvent(const shared_ptr<turboHiker::ModelEvent>& event)
    {
        stringstream message;
        message << "HikerView " << hikerIndex << " received an event: " << event->what() << endl;
        cout << message.str();
        switch (event->eventType)
        {
            case turboHiker::Event::HikerModelEvent:
            {
                cout << "In case HikerEvent" << endl;
                shared_ptr<turboHiker::HikerModelEvent> modelHikerEvent = dynamic_pointer_cast<turboHiker::HikerModelEvent>(event);
                x = modelHikerEvent->getHikerX();
                y = modelHikerEvent->getHikerY();
                sprite.setPosition(x, y);
                hitBox.setPosition(x, y);
            }
                break;
            default:
                break;
        }
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
}