//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERVIEWSFML_H
#define TURBOHIKER_PLAYERHIKERVIEWSFML_H

#include "HikerViewSFML.h"
#include "../../Utilities/Transformation.h"
#include "../../View/HikerView/PlayerHikerView.h"

namespace turboHikerSFML
{
    // Implementation of interface PlayerHikerView from turboHiker library and of interface HikerViewSFML for visual features
    class PlayerHikerViewSFML: public turboHiker::PlayerHikerView, public HikerViewSFML
    {
    public:
        PlayerHikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex);

        // Implementation of abstract function from interface PlayerHikerView
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;

        // Get the difference between the y and the newY, for moving the screen to create illusion the hiker is moving
        double getYOffset() const;
    };
}


#endif //TURBOHIKER_PLAYERHIKERVIEWSFML_H
