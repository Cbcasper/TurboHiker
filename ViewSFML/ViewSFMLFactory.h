//
// Created by Casper De Smet on 17/01/2021.
//

#ifndef TURBOHIKER_VIEWSFMLFACTORY_H
#define TURBOHIKER_VIEWSFMLFACTORY_H

#include "WorldViewSFML.h"
#include "ObstacleViewSFML.h"
#include "HikerViewSFML/PlayerHikerViewSFML.h"
#include "HikerViewSFML/RacingHikerViewSFML.h"
#include "HikerViewSFML/StandingHikerViewSFML.h"
#include "HikerViewSFML/AdversaryHikerViewSFML.h"
#include "../TurboHikerFactory/ViewFactory.h"

namespace turboHikerSFML
{
    class ViewSFMLFactory: public turboHiker::ViewFactory
    {
    public:
        std::shared_ptr<turboHiker::WorldView> getWorldView(const std::weak_ptr<turboHiker::World>& world, double width, double height) override;

        std::shared_ptr<turboHiker::PlayerHikerView> getPlayerHiker(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex) override;
        std::shared_ptr<turboHiker::RacingHikerView> getRacingHiker(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex) override;
        std::shared_ptr<turboHiker::StandingHikerView> getStandingHiker(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, double x, double y) override;
        std::shared_ptr<turboHiker::AdversaryHikerView> getAdversaryHiker(const std::weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, double x, double y) override;

        std::shared_ptr<turboHiker::ObstacleView> getObstacle(const std::weak_ptr<turboHiker::WorldView>& worldView, const std::weak_ptr<turboHiker::LaneView>& lane, double x, double y) override;

        std::shared_ptr<turboHiker::LaneView> getLane(const std::weak_ptr<turboHiker::WorldView>& worldView, int laneIndex, const std::shared_ptr<turboHiker::HikerView>& hiker) override;
    };
}


#endif //TURBOHIKER_VIEWSFMLFACTORY_H
