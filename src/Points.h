#ifndef POINTS_H
#define POINTS_H

#include "ResourceManager.h"

class Points {
public:
  Points(): text(*ResourceManager::getInstance().font)
  {
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
  }

  void update(const float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime >= 1.f) {
      ++points;
      elapsedTime -= 1.f;
    }
    text.setString(std::to_string(points));
  }

  void draw(sf::RenderWindow &window) {
    text.setPosition(sf::Vector2f(window.getSize().x - text.getGlobalBounds().size.x - 20, 20.f));
    window.draw(text);
  }

private:
    int points = 0;
    float elapsedTime = 0;
    sf::Text text;
};

#endif
