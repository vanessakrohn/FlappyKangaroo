#ifndef BACK_H
#define BACK_H

#include <SFML/Graphics.hpp>

class Pipe {
public:
    Pipe(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &startPosition, float height);

    void draw(sf::RenderWindow &window) const;

    void move(float deltaX);

    sf::Vector2f getPosition() const;

    float getWidth() const;

    float getHeight() const;

    bool intersects(const sf::FloatRect &other) const;

private:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
};
#endif
