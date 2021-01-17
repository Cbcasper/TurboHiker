//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_STANDINGHIKERVIEWSFML_H
#define TURBOHIKER_STANDINGHIKERVIEWSFML_H

#include "../../View/HikerView/StandingHikerView.h"
#include "HikerViewSFML.h"
#include "../../Utilities/Transformation.h"

namespace turboHikerSFML
{
    // Implementation of interface StandingHikerView from turboHiker library and of interface HikerViewSFML for visual features
    class StandingHikerViewSFML: public turboHiker::StandingHikerView, public HikerViewSFML
    {
    public:
        // A standing hiker doesn't have a designated initial position, so it should be passed
        StandingHikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, float newX, float newY);

        // Implementation of abstract function
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_STANDINGHIKERVIEWSFML_H
