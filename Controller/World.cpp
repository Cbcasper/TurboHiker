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
    }

    void World::construct()
    {
        worldModel = make_shared<WorldModel>(shared_from_this());
        worldView->setWorld(shared_from_this());

        vector<HikerType> types = {RacingHiker, RacingHiker, RacingHiker, PlayerHiker};

        for (int i = 0; i < 4; ++i)
        {
            worldView->constructLane(i, worldView, {worldView->constructHiker(i, worldView)});
            worldModel->constructLane(i, worldModel, {worldModel->constructHiker(i, worldModel)});
            constructHikerController(i, types[i]);
        }
        game = make_shared<Game>(shared_from_this(), TIMETOLIVE);
    }

    void World::raiseViewEvent(const shared_ptr<ViewEvent>& event)
    {
        cout << "World says: 'A view event was raised: " << event->what() << "'" << endl;
        switch (event->eventType)
        {
            case Event::HikerViewEvent:
//                cout << worldModel->toString() << endl;
//                worldModel->getHiker(dynamic_pointer_cast<HikerViewEvent>(event)->getHikerIndex())->receiveEvent(event);
//                cout << worldModel->toString() << endl;
                hikerControllers[dynamic_pointer_cast<HikerViewEvent>(event)->getHikerIndex()]->raiseEvent(event);
                break;
            default:
                break;
        }
    }

    void World::raiseModelEvent(const shared_ptr<ModelEvent>& event)
    {
//        cout << "World says: 'A model event was raised: " << event->what() << "'" << endl;
        switch (event->eventType)
        {
            case Event::HikerModelEvent:
                worldView->getHiker(dynamic_pointer_cast<HikerModelEvent>(event)->getHikerIndex())->receiveEvent(event);
                break;
            default:
                break;
        }
    }


    void World::raiseGameEvent(const shared_ptr<GameEvent>& event)
    {
        for (const shared_ptr<HikerController>& hikerController: hikerControllers)
            hikerController->raiseGameEvent(event);
        switch (event->gameEventType)
        {
            case GameEvent::Start:
                cout << "World receives Start" << endl;
                break;
            case GameEvent::Stop:
                cout << "World receives Stop" << endl;
                break;
            case GameEvent::ForcedStop:
                game->stop();
                break;
        }
    }

    void World::raiseControllerEvent(const shared_ptr<ControllerEvent>& event)
    {
        switch (event->eventType)
        {
            case Event::HikerControllerEvent:
                worldModel->getHiker(dynamic_pointer_cast<HikerControllerEvent>(event)->getIndex())->receiveEvent(event);
                break;
            default:
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

    void World::run()
    {
        construct();
        worldView->render();
    }

    void World::constructHikerController(int i, HikerType type)
    {
        switch (type)
        {
            case PlayerHiker:
                hikerControllers.emplace_back(make_shared<PlayerHikerController>(shared_from_this(), i));
                break;
            case RacingHiker:
                hikerControllers.emplace_back(make_shared<RacingHikerController>(shared_from_this(), i));
                break;
        }
    }

    World::~World()
    {
        cout << "Destructing this world" << endl;
    }
}