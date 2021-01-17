//
// Created by Casper De Smet on 17/01/2021.
//

#include "ViewSFMLFactory.h"

using namespace std;

namespace turboHikerSFML
{
    shared_ptr<turboHiker::PlayerHikerView> ViewSFMLFactory::getPlayerHiker(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex)
    {
        return make_shared<PlayerHikerViewSFML>(worldView, hikerIndex);
    }

    shared_ptr<turboHiker::RacingHikerView> ViewSFMLFactory::getRacingHiker(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex)
    {
        return make_shared<RacingHikerViewSFML>(worldView, hikerIndex);
    }

    shared_ptr<turboHiker::StandingHikerView> ViewSFMLFactory::getStandingHiker(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, double x, double y)
    {
        return make_shared<StandingHikerViewSFML>(worldView, hikerIndex, x, y);
    }

    shared_ptr<turboHiker::AdversaryHikerView> ViewSFMLFactory::getAdversaryHiker(const weak_ptr<turboHiker::WorldView>& worldView, int hikerIndex, double x, double y)
    {
        return make_shared<AdversaryHikerViewSFML>(worldView, hikerIndex, x, y);
    }

    shared_ptr<turboHiker::ObstacleView> ViewSFMLFactory::getObstacle(const weak_ptr<turboHiker::WorldView>& worldView, const weak_ptr<turboHiker::LaneView>& lane, double x, double y)
    {
        return make_shared<ObstacleViewSFML>(worldView, lane, x, y);
    }

    std::shared_ptr<turboHiker::LaneView> ViewSFMLFactory::getLane(const weak_ptr<turboHiker::WorldView>& worldView, int laneIndex,
                                                                   const shared_ptr<turboHiker::HikerView>& hiker)
    {
        return make_shared<LaneViewSFML>(worldView, laneIndex, hiker);
    }

    shared_ptr<turboHiker::WorldView> ViewSFMLFactory::getWorldView(const weak_ptr<turboHiker::World>& world, double width, double height)
    {
        return make_shared<WorldViewSFML>(world, width, height);
    }
}