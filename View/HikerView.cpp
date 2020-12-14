//
// Created by Casper De Smet on 13/12/2020.
//

#include "HikerView.h"

using namespace std;

namespace turboHiker
{
    HikerView::HikerView(const shared_ptr<WorldView>& worldModel, int hikerIndex): worldModel(worldModel), hikerIndex(hikerIndex)
    {}

    void HikerView::receiveEvent(const shared_ptr<ModelEvent>& event)
    {
        cout << "HikerView " << hikerIndex << " received an event: " << event->what() << endl;
    }
}