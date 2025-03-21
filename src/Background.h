#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background {
public:
    Background() {
        background.setFillColor(sf::Color(173, 216, 230));
    }

    void draw(sf::RenderWindow &window) {
        background.setPosition(sf::Vector2f(0.f, 0.f));
        background.setSize(sf::Vector2f(window.getSize()));
        window.draw(background);
    }

private:
    sf::RectangleShape background;
};
#endif
