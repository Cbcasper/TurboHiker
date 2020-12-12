//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef PLAYGROUND_CONTROLLER_H
#define PLAYGROUND_CONTROLLER_H

#include <iostream>
#include <memory>
#include "../View/WorldView.h"
#include "../Model/WorldModel.h"

using namespace std;

namespace turboHiker
{
    class Controller
    {
    private:
        shared_ptr<WorldModel> worldModel;
        shared_ptr<WorldView> worldView;

    public:
        Controller();
        void raiseEvent(const shared_ptr<Event>& event);

        const shared_ptr<WorldModel>& getWorldModel() const;
        const shared_ptr<WorldView>& getWorldView() const;
    };
}


#endif //PLAYGROUND_CONTROLLER_H
