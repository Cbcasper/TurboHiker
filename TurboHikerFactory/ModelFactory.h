//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_MODELFACTORY_H
#define TURBOHIKER_MODELFACTORY_H

#include "AbstractTurboHikerFactory.h"
#include "../Model/WorldModel.h"
#include "../Model/HikerModel/PlayerHikerModel.h"
#include "../Model/HikerModel/RacingHikerModel.h"
#include "../Model/HikerModel/StandingHikerModel.h"
#include "../Model/HikerModel/AdversaryHikerModel.h"

namespace turboHiker
{
    class ModelFactory: public AbstractTurboHikerFactory
    {
    public:
        std::shared_ptr<AbstractWorldComponent>
        createWorldComponent(const std::weak_ptr<World>& world, double width, double height) override;

        std::shared_ptr<AbstractHiker> createHiker(int hikerIndex, World::HikerType hikerType, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) override;
        std::shared_ptr<AbstractObstacle> createObstacle(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, double x, double y) override;
        std::shared_ptr<AbstractLane> createLane(int laneIndex, const std::weak_ptr<AbstractWorldComponent>& worldComponent, const std::shared_ptr<AbstractHiker>& hiker) override;
    };
}


#endif //TURBOHIKER_MODELFACTORY_H
