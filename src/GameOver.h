#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "ResourceManager.h"

class GameOver {
public:
    GameOver(): text(*ResourceManager::getInstance().font) {
        text.setString("Game over!");
        text.setCharacterSize(150);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
    }

    void draw(sf::RenderWindow &window) {
        text.setPosition(sf::Vector2f(window.getSize().x / 2 - text.getGlobalBounds().size.x / 2,
                                      window.getSize().y / 2 - text.getGlobalBounds().size.y / 2));
        window.draw(text);
    }

private:
    sf::Text text;
};

#endif
