//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_VIEWFACTORY_H
#define TURBOHIKER_VIEWFACTORY_H

#include "AbstractTurboHikerFactory.h"
#include "AbstractWorldComponent.h"
#include "../View/HikerView/HikerView.h"
#include "../View/HikerView/PlayerHikerView.h"
#include "../View/HikerView/RacingHikerView.h"
#include "../View/HikerView/StandingHikerView.h"
#include "../View/HikerView/AdversaryHikerView.h"
#include "../View/ObstacleView.h"

namespace turboHiker
{
    class ViewFactory: public AbstractTurboHikerFactory
    {
    public:
        std::shared_ptr<AbstractWorldComponent> createWorldComponent(const std::weak_ptr<World>& world, double width, double height) override;

        std::shared_ptr<AbstractHiker> createHiker(int hikerIndex, World::HikerType hikerType, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) override;
        std::shared_ptr<AbstractObstacle> createObstacle(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) override;
        std::shared_ptr<AbstractLane> createLane(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, const std::shared_ptr<AbstractHiker>& hiker) override;

        virtual std::shared_ptr<WorldView> getWorldView(const std::weak_ptr<World>& world, double width, double height) = 0;

        virtual std::shared_ptr<PlayerHikerView> getPlayerHiker(const std::weak_ptr<WorldView>& worldView, int hikerIndex) = 0;
        virtual std::shared_ptr<RacingHikerView> getRacingHiker(const std::weak_ptr<WorldView>& worldView, int hikerIndex) = 0;
        virtual std::shared_ptr<StandingHikerView> getStandingHiker(const std::weak_ptr<WorldView>& worldView, int hikerIndex, double x, double y) = 0;
        virtual std::shared_ptr<AdversaryHikerView> getAdversaryHiker(const std::weak_ptr<WorldView>& worldView, int hikerIndex, double x, double y) = 0;

        virtual std::shared_ptr<ObstacleView> getObstacle(const std::weak_ptr<WorldView>& worldView, const std::weak_ptr<LaneView>& lane, double x, double y) = 0;

        virtual std::shared_ptr<LaneView> getLane(const std::weak_ptr<turboHiker::WorldView>& worldView, int laneIndex, const std::shared_ptr<turboHiker::HikerView>& hiker) = 0;
    };
}


#endif //TURBOHIKER_VIEWFACTORY_H
