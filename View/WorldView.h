//
// Created by Casper De Smet on 11/12/2020.
//

#ifndef TURBOHIKER_WORLDVIEW_H
#define TURBOHIKER_WORLDVIEW_H

#include <vector>
#include <memory>
#include <iostream>
#include "LaneView.h"
#include "GameView.h"
#include "ScoringView.h"
#include "HikerView/HikerView.h"
#include "../Event/Event.h"
#include "../Controller/World.h"
#include "../TurboHikerFactory/AbstractWorldComponent.h"

namespace turboHiker
{
    // Interface for the view of the world. Needs to be implemented for the presentation to work.
    class WorldView: public AbstractWorldComponent
    {
    protected:
        // The dimensions of the game
        double screenX;
        double screenY;

        // The world view contains lists of all lanes, hikers and obstacles for easy access
        std::vector<std::shared_ptr<LaneView>> lanes;
        std::vector<std::shared_ptr<HikerView>> hikers;
        std::vector<std::shared_ptr<ObstacleView>> obstacles;
        // It also has a pointer to the game and scoring
        std::shared_ptr<GameView> game;
        std::shared_ptr<ScoringView> scoring;

        // Link to parent object
        std::weak_ptr<World> world;

    public:
        WorldView(const std::weak_ptr<World>& world, double screenX, double screenY);

        const std::shared_ptr<LaneView>& getLane(int index);
        const std::shared_ptr<HikerView>& getHiker(int index);

        virtual void constructGame(const std::weak_ptr<WorldView>& worldView, double finishX, double finishY) = 0;
        virtual void constructScoring(const std::weak_ptr<WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores) = 0;

        // Implementations of abstract functions of interface AbstractWorldComponent
        void addHiker(const std::shared_ptr<AbstractHiker>& hiker) override;
        void addObstacle(const std::shared_ptr<AbstractObstacle>& obstacle) override;
        void addLane(const std::shared_ptr<AbstractLane>& lane) override;
        std::shared_ptr<AbstractLane> getAbstractLane(int laneIndex) override;

        // Abstract function that will be called by the world
        virtual void render() = 0;

        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;

        virtual int getScreenX();
        virtual int getScreenY();

        const std::shared_ptr<ObstacleView>& getObstacle(int obstacleIndex);

        virtual void setPlayerHiker(const std::shared_ptr<HikerView>& hiker) = 0;

        // Change the lane of a hiker according to the event type
        void changeLane(int hikerIndex, Event::EventType eventType);
    };
}


#endif //TURBOHIKER_WORLDVIEW_H
