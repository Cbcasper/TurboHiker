//
// Created by Casper De Smet on 21/12/2020.
//

#include "PlayerHikerView.h"

namespace turboHiker
{
    PlayerHikerView::PlayerHikerView(const std::weak_ptr<WorldView>& worldView, int hikerIndex):
                                     HikerView(worldView, hikerIndex)
    {}
}