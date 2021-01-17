//
// Created by Casper De Smet on 15/01/2021.
//

#include "AdversaryHikerViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    AdversaryHikerViewSFML::AdversaryHikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, float newX, float newY):
            HikerView(worldView, hikerIndex), AdversaryHikerView(worldView, hikerIndex)
    {
        // Accept the position
        x = newX;
        y = newY;
        texture.loadFromFile("waluigi.png");

        // Set the sprite and its scale with the loaded texture
        setSprite();
        sprite.setScale(0.28, 0.28);

        // Set the hitbox with the given scale
        setHitBox(0.18, 0.24);
    }

    void AdversaryHikerViewSFML::handleEvent(const std::shared_ptr<turboHiker::Event>& event)
    {
        // No extra handling of events needed
        HikerViewSFML::handleEvent(event);
    }
}
