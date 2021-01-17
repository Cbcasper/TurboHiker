//
// Created by Casper De Smet on 16/01/2021.
//

#ifndef TURBOHIKER_SCORINGVIEWSFML_H
#define TURBOHIKER_SCORINGVIEWSFML_H

#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../View/ScoringView.h"

namespace turboHikerSFML
{
    // Implementation of interface GameView from turboHiker library and interface Drawable from SFML
    class ScoringViewSFML: public sf::Drawable, public turboHiker::ScoringView
    {
    protected:
        bool duringPreparation;

        // Font for text
        sf::Font font;

        std::vector<sf::Text> highScoresText;

        // The text to display the countdown
        sf::Text currentTimeText;

        // Background for the scoring
        sf::RectangleShape scoringBackground;

    public:
        explicit ScoringViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView, const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores);

        // Implementation of abstract function of interface Drawable
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // Implementations of abstract functions of interface GameView
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;

        // Turn a std::chrono::milliseconds object to text
        std::string currentTimeToText();
        // Add a zero to an int smaller than 10
        static std::string pad(int time);
    };
}


#endif //TURBOHIKER_SCORINGVIEWSFML_H
