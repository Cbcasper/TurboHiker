//
// Created by Casper De Smet on 04/12/2020.
//

#include "World.h"
#include "../View/WorldView.h"
#include "../Model/WorldModel.h"
#include "../TurboHikerFactory/ViewFactory.h"
#include "../TurboHikerFactory/ModelFactory.h"

using namespace std;

namespace turboHiker
{
    World::World(const shared_ptr<ViewFactory>& viewFactory): viewFactory(viewFactory)
    {
        modelFactory = make_shared<ModelFactory>();
    }

    void World::construct()
    {
        // Make a model and a view
        worldView = dynamic_pointer_cast<WorldView>(viewFactory->createWorldComponent(shared_from_this(), 1600, 1600));
        worldModel = dynamic_pointer_cast<WorldModel>(modelFactory->createWorldComponent(shared_from_this(), 200, 800));
        // Set the ratios of the Transformation class with the given dimensions
        Transformation::getInstance().setRatios(worldView->getScreenX(), worldView->getScreenY(),
                                                worldModel->getWorldX(), worldModel->getWorldY(), false);

        vector<HikerType> types = getTypes(4);

        // Construct the hikers and obstacles of a lane and the lane itself
        for (int i = 0; i < 4; ++i)
            constructLanesAndHikers(types[i], i);
        for (int j = 0; j < 4; ++j)
            constructObstacles(j);

        // Get the coordinates of the finish line
        double finishX, finishY;
        tie(finishX, finishY) = Transformation::getInstance().worldToScreen(0, 0);
        // Construct the game view
        worldView->constructGame(worldView, finishX, finishY);

        // Construct the scoring
        worldView->constructScoring(worldView, worldModel->constructScoring());

        // Make the game
        game = make_shared<Game>(shared_from_this(), TIMETOLIVE);
    }

    vector<World::HikerType> World::getTypes(int numberOfHikers)
    {
        // Determine the location of the player hiker
        int playerIndex = Random::getInstance().randomInt(0, 3999);
        vector<HikerType> types;
        // Fill the type vector with the player hiker on the correct spot
        // and racing hikers otherwise
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
            case PlayerHiker: hikerControllers[i] = make_shared<PlayerHikerController>(shared_from_this(), i);          break;
            case RacingHiker: hikerControllers[i] = make_shared<RacingHikerController>(shared_from_this(), i);          break;
            // There is no controller for a standing hiker, since it doesn't move
            case StandingHiker: break;
            case AdversaryHiker: hikerControllers[i] = make_shared<AdversaryHikerController>(shared_from_this(), i);    break;
        }
    }

    void World::constructLanesAndHikers(HikerType hikerType, int index)
    {
        // Each hiker gets a unique index
        static int hikerIndex = 0;
        // Construct a lane and give it the player/racing hiker
        viewFactory->createLane(index, worldView, viewFactory->createHiker(hikerIndex, hikerType, worldView, 0, 0));
        modelFactory->createLane(index, worldModel, modelFactory->createHiker(hikerIndex, hikerType, worldModel, 0, 0));
        // The hiker is fully constructed (view, model, controller), so increment the index
        constructHikerController(hikerIndex++, hikerType);

        // Decide on the number of hikers in the lane
        int numberOfHikersInLane = Random::getInstance().randomInt(1, 3);
        for (int i = 0; i < numberOfHikersInLane; ++i)
        {
            double laneWidth = worldModel->getWorldX() / 4;

            // Compute the position of the hiker
            double x = (laneWidth * index) + (laneWidth / 2);
            // Each hiker has a equal amount of vertical space in the lane to spawn in
            double yReach = ((worldModel->getWorldY() - 100) / numberOfHikersInLane);
            double y = Random::getInstance().randomDouble(yReach * i, yReach * i + yReach);
            // Get the type of the hiker randomly
            HikerType type = Random::getInstance().randomInt(0, 2) ? StandingHiker : AdversaryHiker;

            // Transform the x and y to view coordinates
            double viewX, viewY;
            tie(viewX, viewY) = Transformation::getInstance().worldToScreen(x, y);
            // Construct the hiker in the world, view and controller
            worldView->getLane(index)->addHiker(dynamic_pointer_cast<HikerView>(viewFactory->createHiker(hikerIndex, type, worldView, float(viewX), float(viewY))));
            worldModel->getLane(index)->addHiker(dynamic_pointer_cast<HikerModel>(modelFactory->createHiker(hikerIndex, type, worldModel, x, y)));
            worldModel->getHiker(hikerIndex)->initializeCurrentLane(worldModel->getLane(index));
            // The hiker is fully constructed, so increment the index
            constructHikerController(hikerIndex++, type);
        }
    }

    void World::constructObstacles(int index)
    {
        // Decide on the number of obstacles in the lane
        int numberOfObstacles = Random::getInstance().randomInt(1, 5);

        for (int i = 0; i < numberOfObstacles; ++i)
        {
            // Compute the position
            double laneWidth = worldModel->getWorldX() / 4;
            double x,  y;
            do
            {
                // A random offset within the lane
                x = (laneWidth * index) + Random::getInstance().randomDouble(0, laneWidth);
                // A random y-value
                y = Random::getInstance().randomDouble(0, worldModel->getWorldY() - 100);
            // Check if the position for the obstacle is spaced apart enough
            } while (!worldModel->availableLocation(x, y));

            // Construct the obstacle in view and model
            pair<float, float> position = Transformation::getInstance().worldToScreen(x, y);
            viewFactory->createObstacle(index, worldView, position.first, position.second);
            shared_ptr<ObstacleModel> obstacle = dynamic_pointer_cast<ObstacleModel>(modelFactory->createObstacle(index, worldModel, x, y));
            // Synchronise the hitbox size
            obstacle->setHitboxSize(worldView->getObstacle(obstacle->getIndex())->getHitboxSize());
        }
    }

    void World::handleEvent(const shared_ptr<Event>& event)
    {
        switch (event->eventType)
        {
            case Event::ForceStopGame:
                game->stop();
            case Event::StartCountDown:
            case Event::CountDown:
            case Event::StartGame:
            case Event::StopGame:
                // Pass game events on to the view and controllers
                worldView->handleEvent(event);
                worldModel->handleEvent(event);
                for (const pair<const int, shared_ptr<HikerController>>& hikerController: hikerControllers)
                    hikerController.second->handleEvent(event);
                break;
            // Speed changes are for the relevant hiker controller
            case Event::SpeedUp:
            case Event::SpeedDown:
                if (hikerControllers.find(event->getHikerIndex()) != hikerControllers.end())
                    hikerControllers[event->getHikerIndex()]->handleEvent(event);
                break;
            case Event::Tick:
                // Pass the tick on to the view and model
                worldView->handleEvent(event);
                worldModel->handleEvent(event);
                // Check for collisions and whether the hikers have finished
                worldModel->checkForCollisions();
                if (worldModel->checkIfFinished())
                    game->stop();
                break;
            case Event::MoveLeft:
            case Event::MoveRight:
                // Check whether the hiker can move over
                if (atEdge(event->getHikerIndex(), event->eventType) || !game->started) break;
                // Change the lane in the model and view
                worldModel->changeLane(event->getHikerIndex(), event->eventType);
                worldView->changeLane(event->getHikerIndex(), event->eventType);
            case Event::MoveForward:
            case Event::MoveBackward:
                if (!game->started) break;
                // Pass the event to the hiker model and set it to moving
                worldModel->getHiker(event->getHikerIndex())->handleEvent(event);
                worldModel->getHiker(event->getHikerIndex())->setMoving(true);
                break;
            // Halting and letting go the hiker goes to the relevant hiker controller
            case Event::HaltHiker:
            case Event::LetGoHiker:
                if (hikerControllers.find(event->getHikerIndex()) != hikerControllers.end())
                    hikerControllers[event->getHikerIndex()]->handleEvent(event);
                break;
            // Pass event through to the view
            case Event::HikerStateUpdated:
            case Event::ObstacleStateUpdated:
                worldView->handleEvent(event);
                break;
            // When the hitbox size is requested, fetch it and set it
            case Event::RequestHikerHitboxSize:
                worldModel->getHiker(event->getHikerIndex())->setHitboxSize(worldView->getHiker(event->getHikerIndex())->getHitboxSize());
                break;
            case Event::RequestObstacleHitBoxSize:
                worldModel->getObstacle(event->getObstacleIndex())->setHitboxSize(worldView->getObstacle(event->getObstacleIndex())->getHitboxSize());
                break;
            case Event::CollisionWithHiker:
                // Only handle the collision if your index is smaller to prevent both hikers handling the collision
                if (event->getHikerIndex() < event->getOtherHikerIndex())
                    if (hikerControllers.find(event->getHikerIndex()) != hikerControllers.end())
                        hikerControllers[event->getHikerIndex()]->handleEvent(event);
                break;
            case Event::CollisionWithObstacle:
                // Decide whether the obstacle breaks or the hiker gets stopped
                if (Random::getInstance().randomInt(0, 1))
                {
                    if (hikerControllers.find(event->getHikerIndex()) != hikerControllers.end())
                        hikerControllers[event->getHikerIndex()]->handleEvent(event);
                }
                else
                    worldModel->getObstacle(event->getObstacleIndex())->goBroken();
                break;
            case Event::HikerFinished:
                break;
            // Set the value of moving of the right hiker accordingly
            case Event::StopMoving:
                worldModel->getHiker(event->getHikerIndex())->setMoving(false);
                break;
            case Event::StartMoving:
                worldModel->getHiker(event->getHikerIndex())->setMoving(true);
                break;
            case Event::Jump:
                worldModel->getHiker(event->getHikerIndex())->handleEvent(event);
                break;
            case Event::GamePrepared:
                // Start the game when it is prepared
                game->start();
                worldModel->handleEvent(event);
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

    bool World::atEdge(int hikerIndex, Event::EventType eventType)
    {
        // Get the lane the hiker is in
        int laneIndex = worldModel->getHiker(hikerIndex)->getLaneIndex();
        switch (eventType)
        {
            // Check if at edge and return result
            case Event::MoveLeft:   if (laneIndex > 0) return false;    break;
            case Event::MoveRight:  if (laneIndex < 3) return false;    break;
            default:                                                    break;
        }
        return true;
    }
}