//
// Created by Casper De Smet on 22/12/2020.
//

#ifndef TURBOHIKER_GAMEVIEWSFML_H
#define TURBOHIKER_GAMEVIEWSFML_H

#include "iostream"
#include <SFML/Graphics.hpp>
#include "../View/GameView.h"

namespace turboHikerSFML
{
    class GameViewSFML: public turboHiker::GameView, public sf::Drawable
    {
    private:
        sf::Font font;
        sf::Text countDownText;

    public:
        GameViewSFML();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

//        void receiveGameEvent(const std::shared_ptr<turboHiker::GameEvent>& event) override;

        void handleEvent(const std::shared_ptr<turboHiker::Event>& event) override;
    };
}


#endif //TURBOHIKER_GAMEVIEWSFML_H
