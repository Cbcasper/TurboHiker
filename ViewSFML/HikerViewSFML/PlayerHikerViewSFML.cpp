//
// Created by Casper De Smet on 21/12/2020.
//

#include "PlayerHikerViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    PlayerHikerViewSFML::PlayerHikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex) :
            PlayerHikerView(worldView, hikerIndex), HikerView(worldView, hikerIndex)
    {
        texture.loadFromFile("mario.png");

        // Set the sprite and its scale with the loaded texture
        setSprite();
        sprite.setScale(0.145, 0.145);

        // Set the hitbox with the given scale
        setHitBox(0.06, 0.09);
    }

    void PlayerHikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        // No further event handling needed
        HikerViewSFML::handleEvent(event);
    }

    double PlayerHikerViewSFML::getYOffset() const
    {
        return abs(y - newY);
    }
}