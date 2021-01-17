//
// Created by Casper De Smet on 10/12/2020.
//

#ifndef TURBOHIKER_WORLDMODEL_H
#define TURBOHIKER_WORLDMODEL_H

#include <vector>
#include <memory>
#include <string>
#include "LaneModel.h"
#include "HikerModel/PlayerHikerModel.h"
#include "HikerModel/RacingHikerModel.h"
#include "HikerModel/StandingHikerModel.h"
#include "HikerModel/AdversaryHikerModel.h"
#include "../Controller/World.h"
#include "../TurboHikerFactory/AbstractWorldComponent.h"

namespace turboHiker
{
    class WorldModel: public AbstractWorldComponent
    {
    private:
        double worldX;
        double worldY;

        // Link to parent object
        std::weak_ptr<World> world;

        // The world model contains lists of all lanes, hikers and obstacles for easy access
        std::vector<std::shared_ptr<LaneModel>> lanes;
        std::vector<std::shared_ptr<HikerModel>> hikers;
        std::vector<std::shared_ptr<ObstacleModel>> obstacles;

        // Store the player hiker again separately for easy access
        std::shared_ptr<PlayerHikerModel> playerHiker;

        std::shared_ptr<ScoringModel> scoring;

    public:
        // Objects to check for during collision detection
        enum CheckFor {Hikers, Obstacles, Both};

        WorldModel(const std::weak_ptr<World>& world, double worldX, double worldY);

        // Implementations of abstract functions of interface AbstractWorldComponent
        void addHiker(const std::shared_ptr<AbstractHiker>& hiker) override;
        void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) override;
        void addLane(const std::shared_ptr<AbstractLane>& lane) override;
        std::shared_ptr<AbstractLane> getAbstractLane(int laneIndex) override;

        std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>> constructScoring();

        // Pass an event through to the world
        void raiseEvent(const std::shared_ptr<Event>& event);

        std::string toString();

        // Getters for the hikers, obstacles and lanes
        const std::shared_ptr<HikerModel>& getHiker(int hikerIndex);
        const std::shared_ptr<ObstacleModel>& getObstacle(int obstacleIndex);
        const std::shared_ptr<LaneModel>& getLane(int index) const;

        void setPlayerHiker(const std::shared_ptr<HikerModel>& hiker);

        double getWorldX() const;
        double getWorldY() const;

        void changeLane(int hikerIndex, Event::EventType eventType);

        void handleEvent(const std::shared_ptr<Event>& event);

        // Check whether an obstacle on a given position would be spaced out enough
        bool availableLocation(double x, double y);

        void checkForCollisions();
        std::vector<std::shared_ptr<Event>> checkForCollisions(const std::shared_ptr<HikerModel>& hiker);
        std::vector<std::shared_ptr<Event>> checkForCollisions(const std::shared_ptr<Hitbox>& hitbox, int hikerIndex, CheckFor checkFor);

        bool checkIfFinished();
    };
}

#endif //TURBOHIKER_WORLDMODEL_H
