#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
public:
    explicit Character(const sf::Vector2f &startPosition);

    void update(float deltaTime);

    void draw(sf::RenderWindow &window) const;

    bool isOutsideWindow(const sf::RenderWindow &window) const;

    sf::Vector2f getPosition() const;

    sf::FloatRect getCollisionBox() const;

    float getWidth() const;

    float getHeight() const;

private:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;

    float velocity = 0.f;
    float gravity = 580.f;
    float flapStrength = -520.f;
    int flapCooldownInMs = 1000.f;

    sf::Clock clock;

    void handleInput();

    void handleGravity(float deltaTime);
};

#endif
