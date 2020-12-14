//
// Created by Casper De Smet on 04/12/2020.
//

#include "World.h"

using namespace std;

namespace turboHiker
{
    World::World(const shared_ptr<WorldView>& worldView): worldView(worldView)
    {
        cout << "Constructing this world!" << endl;
        shared_ptr<World> world = make_shared<World>(*this);
        worldModel = make_shared<WorldModel>(world);
        worldView->setWorld(world);
    }

    void World::raiseViewEvent(const shared_ptr<ViewEvent>& event)
    {
        cout << "World says: 'A view event was raised: " << event->what() << "'" << endl;
        switch (event->eventType)
        {
            case Event::ClickEvent:
                break;
            case Event::HikerEvent:

                break;
        }
    }

    const shared_ptr<WorldModel>& World::getModel() const
    {
        return worldModel;
    }

    const shared_ptr<WorldView>& World::getView() const
    {
        return worldView;
    }

    void World::start()
    {
        worldModel->start();
        worldModel->wait();
    }

    void World::raiseModelEvent(const shared_ptr<ModelEvent>& event)
    {
//        cout << "World says: 'A model event was raised: " << event->what() << "'" << endl;
        switch (event->eventType)
        {
            case Event::ClickEvent:
                break;
            case Event::HikerEvent:
                worldView->getHiker(dynamic_pointer_cast<ModelHikerEvent>(event)->getHikerIndex())->receiveEvent(event);
                break;
        }
    }
}