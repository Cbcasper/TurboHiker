//
// Created by Casper De Smet on 22/12/2020.
//

#ifndef TURBOHIKER_GAMEVIEWSFML_H
#define TURBOHIKER_GAMEVIEWSFML_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../View/GameView.h"

namespace turboHikerSFML
{
    // Implementation of interface GameView from turboHiker library and interface Drawable from SFML
    class GameViewSFML: public turboHiker::GameView, public sf::Drawable
    {
    private:
        // Font used for text
        sf::Font font;

        // Loading screen background
        sf::Texture backgroundTexture;
        sf::RectangleShape background;

        // The loading label, name and background for the name
        // The label is split into sentences for alignment purposes
        std::vector<sf::Text> label;
        sf::Text name;
        sf::RectangleShape nameBackground;

        // Text used to display
        sf::Text countDownText;

        // Texture and shape for finish line
        sf::Texture finishTexture;
        sf::RectangleShape finishLine;


    public:
        // Whether the game is during preparation
        bool duringPreparation;

        explicit GameViewSFML(const std::weak_ptr<turboHiker::WorldView>& worldView);

        // Function to initialize a given text with given parameters
        void initialiseText(sf::Text& text, const std::string& content, int fontSize, const sf::Color& color, float x, float y);

        // Implementation of abstract function of interface Drawable
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // Implementations of abstract functions of interface GameView
        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
        void setFinishLinePosition(double x, double y) override;
        void scroll(double yOffset) override;

        // Add text entered to the name
        void enterText(unsigned int character);
        // Accept entered name
        void acceptName();
    };
}


#endif //TURBOHIKER_GAMEVIEWSFML_H
