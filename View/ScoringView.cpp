//
// Created by Casper De Smet on 16/01/2021.
//

#include "ScoringView.h"

using namespace std;

namespace turboHiker
{
    // At construction time the currentTime is zero
    ScoringView::ScoringView(const std::weak_ptr<WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores):
    worldView(worldView), currentTime(chrono::milliseconds(0)), highScores(highScores)
    {}
}