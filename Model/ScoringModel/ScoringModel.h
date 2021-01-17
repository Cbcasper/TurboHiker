//
// Created by Casper De Smet on 08/12/2020.
//

#ifndef TURBOHIKER_SCORINGMODEL_H
#define TURBOHIKER_SCORINGMODEL_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <algorithm>
#include "HikerScore.h"

namespace turboHiker
{
    class ScoringModel
    {
    private:
        // The name of the player
        std::string playerName;
        // Score for the player hiker
        std::shared_ptr<HikerScore> playerHikerScore;

    public:
        ScoringModel();
        virtual ~ScoringModel() = default;

        void setPlayerName(const std::string& newPlayerName);

        // Write the score to the high score file
        void writeScore();
        static std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>> readScore();

        void update(const std::chrono::milliseconds& gameLength);

        static std::chrono::milliseconds textToTime(const std::string& text);
        static std::string timeToText(const std::chrono::milliseconds& gameLength);
        static std::string pad(int time);
    };
}


#endif //TURBOHIKER_SCORINGMODEL_H
