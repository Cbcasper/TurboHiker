//
// Created by Casper De Smet on 16/01/2021.
//

#include "ScoringViewSFML.h"
#include "WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    ScoringViewSFML::ScoringViewSFML(const weak_ptr<turboHiker::WorldView>& worldView,
                                     const std::vector<std::tuple<std::chrono::milliseconds, std::string, std::string>>& highScores):
                                     ScoringView(worldView, highScores), duringPreparation(true)
    {
        // Load the font
        font.loadFromFile("arial.ttf");

        // Set the current time text
        currentTimeText = sf::Text(currentTimeToText(), font);
        currentTimeText.setCharacterSize(150);
        currentTimeText.setStyle(sf::Text::Bold);
        currentTimeText.setFillColor(sf::Color::White);
        currentTimeText.setPosition(50, float (worldView.lock()->getScreenY()));

        // Set the parameters of the high scores
        highScoresText = vector<sf::Text>(3, sf::Text());
        for (int i = 0; i < 3; ++i)
        {
            sf::Text& text = highScoresText[i];
            text = sf::Text(get<2>(highScores[i]) + " " + get<1>(highScores[i]), font, 50);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::White);
            text.setPosition(float(worldView.lock()->getScreenX() / 2.0), float(worldView.lock()->getScreenY() + (60 * i)));
        }

        // Set the parameters of the scoring background
        scoringBackground.setSize(sf::Vector2f(worldView.lock()->getScreenX(), 200));
        scoringBackground.setPosition(0, float (worldView.lock()->getScreenY()));
        scoringBackground.setFillColor(sf::Color::Black);
    }

    void ScoringViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(scoringBackground);
        target.draw(currentTimeText);
        for (const sf::Text& text: highScoresText)
            target.draw(text);
    }

    void ScoringViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::Tick:
                // Add a millisecond and update the sf::Text object
                currentTime += chrono::milliseconds(1);
                currentTimeText.setString(currentTimeToText());
                break;
            case turboHiker::Event::StartGame:
                duringPreparation = false;
                break;
            default:
                break;
        }
    }

    std::string ScoringViewSFML::currentTimeToText()
    {
        // Get the seconds the time translates to
        int seconds = chrono::duration_cast<chrono::seconds>(currentTime).count();
        // Get the remaining milliseconds
        int remainingMilliseconds = int (currentTime.count() - (seconds * 1000));
        stringstream text;
        text << pad(seconds) << ":" << pad(remainingMilliseconds / 10) << endl;
        return text.str();
    }

    std::string ScoringViewSFML::pad(int time)
    {
        // Check whether the time is smaller than 10 and add a zero accordingly
        stringstream text;
        if (time < 10)
            text << '0';
        text << time;
        return text.str();
    }
}
