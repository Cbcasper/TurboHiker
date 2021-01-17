//
// Created by Casper De Smet on 15/01/2021.
//

#include "StandingHikerViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    StandingHikerViewSFML::StandingHikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, float newX, float newY):
            StandingHikerView(worldView, hikerIndex), HikerView(worldView, hikerIndex)
    {
        // Accept the position
        x = newX;
        y = newY;
        texture.loadFromFile("bowser.png");

        // Set the sprite and its scale with the loaded texture
        setSprite();
        sprite.setScale(0.47, 0.47);

        // Set the hitbox with the given scale
        setHitBox(0.32, 0.28);
    }

    void StandingHikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        // No further event handling needed
        HikerViewSFML::handleEvent(event);
    }
}