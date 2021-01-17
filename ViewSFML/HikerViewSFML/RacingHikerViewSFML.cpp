//
// Created by Casper De Smet on 21/12/2020.
//

#include "RacingHikerViewSFML.h"

using namespace std;

namespace turboHikerSFML
{

    RacingHikerViewSFML::RacingHikerViewSFML(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex) :
            RacingHikerView(worldView, hikerIndex), HikerView(worldView, hikerIndex)
    {
        texture.loadFromFile("luigi.png");

        // Set the sprite and its scale with the loaded texture
        setSprite();
        sprite.setScale(0.125, 0.125);

        // Set the hitbox with the given scale
        setHitBox(0.085, 0.1);
    }

    void RacingHikerViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        // No further event handling needed
        HikerViewSFML::handleEvent(event);
    }
}