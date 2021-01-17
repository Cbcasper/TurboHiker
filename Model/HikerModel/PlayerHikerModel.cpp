//
// Created by Casper De Smet on 21/12/2020.
//

#include "PlayerHikerModel.h"

using namespace std;

namespace turboHiker
{
    PlayerHikerModel::PlayerHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex) :
            HikerModel(worldModel, hikerIndex)
    {}

    void PlayerHikerModel::setScoring(const shared_ptr<ScoringModel>& givenScoring)
    {
        scoring = givenScoring;
    }

    void PlayerHikerModel::handleEvent(const shared_ptr<Event>& event)
    {
        HikerModel::handleEvent(event);
        switch (event->eventType)
        {
            case Event::StopGame: scoring->update(event->getGameLength());  break;
            default:                                                        break;
        }
    }
}