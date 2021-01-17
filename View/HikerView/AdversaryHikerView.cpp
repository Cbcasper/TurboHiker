//
// Created by Casper De Smet on 15/01/2021.
//

#include "AdversaryHikerView.h"

using namespace std;

namespace turboHiker
{
    AdversaryHikerView::AdversaryHikerView(const weak_ptr<WorldView>& worldView, int hikerIndex) :
            HikerView(worldView, hikerIndex)
    {}
}