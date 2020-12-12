//
// Created by Casper De Smet on 04/12/2020.
//

#include "Controller.h"

namespace turboHiker
{
    Controller::Controller()
    {
        cout << "Constructing this controller!" << endl;
        shared_ptr<Controller> controller = make_shared<Controller>(*this);
        worldModel = make_shared<WorldModel>(controller);
        worldView = make_shared<WorldView>(controller);
    }

    void Controller::raiseEvent(const shared_ptr<Event>& event)
    {
        cout << "Controller says: 'An event was raised: " << event->what() << "'" << endl;
    }

    const shared_ptr<WorldModel>& Controller::getWorldModel() const
    {
        return worldModel;
    }

    const shared_ptr<WorldView>& Controller::getWorldView() const
    {
        return worldView;
    }
}