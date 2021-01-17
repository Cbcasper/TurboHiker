//
// Created by Casper De Smet on 21/12/2020.
//

#ifndef TURBOHIKER_PLAYERHIKERMODEL_H
#define TURBOHIKER_PLAYERHIKERMODEL_H

#include "HikerModel.h"
#include "../ScoringModel/ScoringModel.h"

namespace turboHiker
{
    class PlayerHikerModel: public HikerModel
    {
    private:
        // Scoring, to be updated through the observer pattern
        std::shared_ptr<ScoringModel> scoring;

    public:
        PlayerHikerModel(const std::weak_ptr<WorldModel>& worldModel, int hikerIndex);

        void handleEvent(const std::shared_ptr<Event>& event) override;

        void setScoring(const std::shared_ptr<ScoringModel>& givenScoring);
    };
}

#endif //TURBOHIKER_PLAYERHIKERMODEL_H
