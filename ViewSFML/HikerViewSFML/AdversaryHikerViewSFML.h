//
// Created by Casper De Smet on 15/01/2021.
//

#ifndef TURBOHIKER_ADVERSARYHIKERVIEWSFML_H
#define TURBOHIKER_ADVERSARYHIKERVIEWSFML_H

#include "HikerViewSFML.h"
#include "../../Utilities/Transformation.h"
#include "../../View/HikerView/AdversaryHikerView.h"

namespace turboHikerSFML
{
    // Implementation of interface AdversaryHikerView from turboHiker library and of interface HikerViewSFML for visual features
    class AdversaryHikerViewSFML: public turboHiker::AdversaryHikerView, public HikerViewSFML
    {
    public:
        // An adversary hiker doesn't have a designated initial position, so it should be passed
        AdversaryHikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, float newX, float newY);

        // Implementation of abstract function
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_ADVERSARYHIKERVIEWSFML_H
