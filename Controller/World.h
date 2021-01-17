//
// Created by Casper De Smet on 04/12/2020.
//

#ifndef TURBOHIKER_WORLD_H
#define TURBOHIKER_WORLD_H

#define TIMETOLIVE 60

#include <iostream>
#include <vector>
#include <memory>
#include "Game.h"
#include "HikerController/HikerController.h"
#include "HikerController/PlayerHikerController.h"
#include "HikerController/ComputerHikerController/AdversaryHikerController.h"
#include "HikerController/ComputerHikerController/RacingHikerController.h"
#include "../Utilities/Random.h"
#include "../Model/ObstacleModel.h"

namespace turboHiker
{
    class WorldView;
    class WorldModel;
    class ViewFactory;
    class ModelFactory;

    class World: public std::enable_shared_from_this<World>
    {
    public:
        // Types of hikers
        enum HikerType {PlayerHiker, RacingHiker, StandingHiker, AdversaryHiker};

    private:
        std::shared_ptr<ViewFactory> viewFactory;
        std::shared_ptr<ModelFactory> modelFactory;

        std::shared_ptr<Game> game;
        std::shared_ptr<WorldView> worldView;
        std::shared_ptr<WorldModel> worldModel;
        std::map<int, std::shared_ptr<HikerController>> hikerControllers;

        // Construct all lanes, hikers and obstacles
        void construct();

        // Construct all the lane and all the hikers in it
        void constructLanesAndHikers(HikerType hikerType, int index);
        // Construct the obstacles of a lane
        void constructObstacles(int index);
        // Construct the controller i with a given type
        void constructHikerController(int i, HikerType type);

        // Get a vector with four types: three racing hikers and a player hiker in a random lane
        static std::vector<HikerType> getTypes(int numberOfHikers);

    public:
        explicit World(const std::shared_ptr<ViewFactory>& viewFactory);
        virtual ~World() = default;

        void handleEvent(const std::shared_ptr<Event>& event);

        // Check if an hiker is at an edge and whether it's going over the edge at a certain event
        bool atEdge(int hikerIndex, Event::EventType eventType);

        const std::shared_ptr<WorldModel>& getModel() const;
        const std::shared_ptr<WorldView>& getView() const;

        void run();
    };
}


#endif //TURBOHIKER_WORLD_H
