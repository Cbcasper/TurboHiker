//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_RACINGHIKERVIEWSFML_H
#define TURBOHIKER_RACINGHIKERVIEWSFML_H

#include "../../View/HikerView/RacingHikerView.h"
#include "HikerViewSFML.h"
#include "../../Utilities/Transformation.h"

namespace turboHikerSFML
{
    // Implementation of interface RacingHikerView from turboHiker library and of interface HikerViewSFML for visual features
    class RacingHikerViewSFML: public turboHiker::RacingHikerView, public HikerViewSFML
    {
    public:
        RacingHikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex);

        // Implementation of abstract function
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_RACINGHIKERVIEWSFML_H
