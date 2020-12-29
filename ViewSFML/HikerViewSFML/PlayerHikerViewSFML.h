//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERVIEWSFML_H
#define TURBOHIKER_PLAYERHIKERVIEWSFML_H

#include "../../View/HikerView/PlayerHikerView.h"
#include "HikerViewSFML.h"
#include "../../Event/ModelEvent/HikerModelEvent.h"
#include "../../Utilities/Transformation.h"

namespace turboHikerSFML
{
    class PlayerHikerViewSFML: public turboHiker::PlayerHikerView, public HikerViewSFML
    {
    public:
        PlayerHikerViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex);

        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_PLAYERHIKERVIEWSFML_H
