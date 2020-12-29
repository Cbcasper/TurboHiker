//
// Created by Casper De Smet on 21/12/2020.
//

#include "RacingHikerView.h"

namespace turboHiker
{
    RacingHikerView::RacingHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex):
                                     HikerView(worldView, hikerIndex)
    {}
}