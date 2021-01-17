//
// Created by Casper De Smet on 22/12/2020.
//

#include "GameViewSFML.h"
#include "WorldViewSFML.h"

using namespace std;

namespace turboHikerSFML
{
    GameViewSFML::GameViewSFML(const weak_ptr<turboHiker::WorldView>& worldView): GameView(worldView), duringPreparation(true)
    {
        // Load font and backgroundTexture
        font.loadFromFile("arial.ttf");
        backgroundTexture.loadFromFile("cobblePath.png");

        // Set parameters of background
        background = sf::RectangleShape(sf::Vector2f(worldView.lock()->getScreenX(), worldView.lock()->getScreenY()));
        background.setTexture(&backgroundTexture);
        background.setTextureRect(sf::IntRect(0, 0, 2048, 2048));
        background.setPosition(0, 0);

        // Determine the center of the screen
        float centerX = float(worldView.lock()->getScreenX() / 2.0);
        float centerY = float(worldView.lock()->getScreenY() / 2.0);

        // Set the content of the label and initialize the sf::Text objects
        vector<string> labelContent = {"What's your name?", "Press enter to continue."};
        label = vector<sf::Text>(labelContent.size(), sf::Text());

        // Initialize all text objects
        for (int i = 0; i < label.size(); i++)
            initialiseText(label[i], labelContent[i], 50, sf::Color::White, centerX, centerY - float (100 + (50 * label.size())) + float (50 * i));
        initialiseText(name, string(), 50, sf::Color::White, centerX - 200, centerY);
        initialiseText(countDownText, to_string(countDown), 300, sf::Color(255, 205, 0), centerX, centerY);

        // Set parameters of name background
        nameBackground = sf::RectangleShape(sf::Vector2f(420, 70));
        nameBackground.setFillColor(sf::Color::Black);
        nameBackground.setPosition(centerX - 210, centerY);
        nameBackground.setOutlineColor(sf::Color::White);
        nameBackground.setOutlineThickness(5);

        // Set parameters of finish line
        finishTexture.loadFromFile("finishLine.png");
        finishLine.setTexture(&finishTexture);
        finishLine.setTextureRect(sf::IntRect(0, 0, worldView.lock()->getScreenX(), 145));
        finishLine.setSize(sf::Vector2f(worldView.lock()->getScreenX(), 145));
        finishLine.setPosition(0, 0);
        finishLine.setFillColor(sf::Color::White);
    }

    void GameViewSFML::initialiseText(sf::Text& text, const std::string& content, int fontSize, const sf::Color& color, float x, float y)
    {
        // Apply the given parameters
        text = sf::Text(content, font, fontSize);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(color);

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
        text.setPosition(x, y);
    }

    void GameViewSFML::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (duringPreparation)
        {
            target.draw(background);
            for (const sf::Text& text: label)
                target.draw(text);
            target.draw(nameBackground);
            target.draw(name);
        }
        else if (onCountDown)
            target.draw(countDownText);
        target.draw(finishLine);
    }

    void GameViewSFML::setFinishLinePosition(double x, double y)
    {
        finishLine.setPosition(float(x), float(y));
    }

    void GameViewSFML::scroll(double yOffset)
    {
        // Move the finish line by a given offset
        sf::Vector2f position = finishLine.getPosition();
        position.y += yOffset;
        finishLine.setPosition(position);
    }

    void GameViewSFML::handleEvent(const shared_ptr<turboHiker::Event>& event)
    {
        switch (event->eventType)
        {
            case turboHiker::Event::StartCountDown:
                onCountDown = true;
                break;
            case turboHiker::Event::CountDown:
                countDownText.setString(to_string(countDown));
                countDown--;
                break;
            case turboHiker::Event::StartGame:
                onCountDown = false;
                break;
            default:
                break;
        }
    }

    void GameViewSFML::enterText(unsigned int character)
    {
        // If we're listening to the name, add the entered character to the name
        if (duringPreparation)
            name.setString(name.getString() + character);
    }

    void GameViewSFML::acceptName()
    {
        // Stop preparation and pass through the name of the player
        duringPreparation = false;
        dynamic_pointer_cast<WorldViewSFML>(worldView.lock())->raiseEvent(make_shared<turboHiker::Event>(turboHiker::Event::GamePrepared, name.getString()));
    }
}