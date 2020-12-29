//
// Created by Casper De Smet on 04/12/2020.
//

#include "World.h"
#include "../View/WorldView.h"
#include "../Model/WorldModel.h"
#include "../Utilities/Transformation.h"

using namespace std;

namespace turboHiker
{
    World::World(const shared_ptr<WorldView>& worldView): worldView(worldView)
    {
        cout << "Constructing this world!" << endl;
    }

    void World::construct()
    {
        worldModel = make_shared<WorldModel>(shared_from_this(), 200, 1000);
        worldView->setWorld(shared_from_this());
        Transformation::getInstance().setRatios(worldView->getScreenX(), worldView->getScreenY(),
                                                worldModel->getWorldX(), worldModel->getWorldY(), false);

        vector<HikerType> types = getTypes(4);

        for (int i = 0; i < 4; ++i)
        {
            worldView->constructLane(i, worldView, {worldView->constructHiker(i, types[i], worldView)});
            worldModel->constructLane(i, worldModel, {worldModel->constructHiker(i, types[i], worldModel)});
            constructHikerController(i, types[i]);
        }
        worldView->constructGame();
        game = make_shared<Game>(shared_from_this(), TIMETOLIVE);
    }

    vector<World::HikerType> World::getTypes(int numberOfHikers)
    {
        int playerIndex = Random::getInstance().randomInt(0, 3999);
        vector<HikerType> types;
        for (int i = 0; i < numberOfHikers; ++i)
            if (i == playerIndex / 1000)
                types.emplace_back(PlayerHiker);
            else
                types.emplace_back(RacingHiker);
        return types;
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

//    void World::raiseViewEvent(const shared_ptr<ViewEvent>& event)
//    {
//        cout << "World says: 'A view event was raised: " << event->what() << "'" << endl;
//        switch (event->eventType)
//        {
//            case Event::HikerViewEvent:
////                cout << worldModel->toString() << endl;
////                worldModel->getHiker(dynamic_pointer_cast<HikerViewEvent>(event)->getHikerIndex())->receiveEvent(event);
////                cout << worldModel->toString() << endl;
//                hikerControllers[dynamic_pointer_cast<HikerViewEvent>(event)->getHikerIndex()]->handleEvent(event);
//                break;
//            default:
//                break;
//        }
//    }

//    void World::raiseModelEvent(const shared_ptr<ModelEvent>& event)
//    {
////        cout << "World says: 'A model event was raised: " << event->what() << "'" << endl;
//        switch (event->eventType)
//        {
//            case Event::HikerModelEvent:
//                worldView->getHiker(dynamic_pointer_cast<HikerModelEvent>(event)->getHikerIndex())->handleEvent(event);
//                break;
//            default:
//                break;
//        }
//    }

//    void World::raiseGameEvent(const shared_ptr<GameEvent>& event)
//    {
//        worldView->receiveGameEvent(event);
//        for (const shared_ptr<HikerController>& hikerController: hikerControllers)
//            hikerController->raiseGameEvent(event);
//        switch (event->gameEventType)
//        {
//            case GameEvent::Start:
//                cout << "World receives Start" << endl;
//                break;
//            case GameEvent::Stop:
//                cout << "World receives Stop" << endl;
//                break;
//            case GameEvent::ForcedStop:
//                game->stop();
//                break;
//            default:
//                break;
//        }
//    }

//    void World::raiseControllerEvent(const shared_ptr<ControllerEvent>& event)
//    {
//        switch (event->eventType)
//        {
//            case Event::HikerControllerEvent:
//            {
//                shared_ptr<HikerControllerEvent> hikerControllerEvent = dynamic_pointer_cast<HikerControllerEvent>(event);
//                if (hikerControllerEvent->hikerEventType == HikerEvent::Move &&
//                        (hikerControllerEvent->direction == HikerEvent::Left ||
//                         hikerControllerEvent->direction == HikerEvent::Right))
//                {
//                    worldModel->changeLane(hikerControllerEvent->getHikerIndex(),
//                                           hikerControllerEvent->getNewLaneIndex());
//                    worldView->changeLane(hikerControllerEvent->getHikerIndex(),
//                                          hikerControllerEvent->getNewLaneIndex());
//                }
//                worldModel->getHiker(hikerControllerEvent->getHikerIndex())->handleEvent(hikerControllerEvent);
//            }
//                break;
//            default:
//                break;
//        }
//    }

    void World::handleEvent(const shared_ptr<Event>& event)
    {
        stringstream message;
        message << "World is handling an event: " << event->what() << endl;
        cout << message.str();
        switch (event->eventType)
        {
            case Event::ForceStopGame:
                game->stop();
            case Event::StartCountDown:
            case Event::CountDown:
            case Event::StartGame:
            case Event::StopGame:
                worldView->handleEvent(event);
            case Event::SpeedUp:
            case Event::SpeedDown:
                for (const shared_ptr<HikerController>& hikerController: hikerControllers)
                    hikerController->handleEvent(event);
                break;
            case Event::MoveLeft:
            case Event::MoveRight:
                worldModel->changeLane(event->getHikerIndex(), event->eventType);
                worldView->changeLane(event->getHikerIndex(), event->eventType);
            case Event::MoveForward:
                worldModel->getHiker(event->getHikerIndex())->handleEvent(event);
                break;
            case Event::StateUpdated:
                worldView->getHiker(event->getHikerIndex())->handleEvent(event);
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

    World::~World()
    {
        cout << "Destructing this world" << endl;
    }
}