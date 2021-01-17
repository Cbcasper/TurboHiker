//
// Created by Casper De Smet on 16/01/2021.
//

#ifndef TURBOHIKER_SCORINGVIEW_H
#define TURBOHIKER_SCORINGVIEW_H

#include <chrono>
#include <memory>
#include <tuple>
#include <vector>
#include "../Event/Event.h"

namespace turboHiker
{
    class WorldView;

    // Interface for the view of the scoring. Must be implemented for the presentation to work.
    class ScoringView
    {
    protected:
        // Time the game has run for
        std::chrono::milliseconds currentTime;

        // Link to parent objects
        std::weak_ptr<WorldView> worldView;

        std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>> highScores;

    public:
        explicit ScoringView(const std::weak_ptr<WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores);

        // Abstract function that will be called by the world
        virtual void handleEvent(const std::shared_ptr<Event>& event) = 0;
    };
}


#endif //TURBOHIKER_SCORINGVIEW_H
