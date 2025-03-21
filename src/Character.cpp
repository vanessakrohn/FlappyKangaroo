#include "Character.h"
#include <SFML/Window/Keyboard.hpp>

#include "ResourceManager.h"

Character::Character(const sf::Vector2f &startPosition): texture(ResourceManager::getInstance().characterTexture),
                                                         sprite(*texture) {
    sprite.setPosition(startPosition);
    constexpr sf::Vector2f desiredSize(100.f, 50.f);
    const sf::Vector2u textureSize = texture->getSize();
    const sf::Vector2f scaleFactors(
        desiredSize.x / static_cast<float>(textureSize.x),
        desiredSize.y / static_cast<float>(textureSize.y));
    sprite.setScale(scaleFactors);
}

void Character::update(const float deltaTime) {
    handleInput();
    handleGravity(deltaTime);
}

void Character::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

bool Character::isOutsideWindow(const sf::RenderWindow &window) const {
    return getPosition().y > static_cast<float>(window.getSize().y) || getPosition().y + getHeight() < 0.f;
}

sf::FloatRect Character::getCollisionBox() const {
    constexpr auto deadZone = 20;
    const sf::FloatRect bounds = sprite.getGlobalBounds();
    return sf::FloatRect(
        bounds.position + sf::Vector2f(deadZone, deadZone),
        bounds.size - sf::Vector2f(2 * deadZone, 2 * deadZone)
    );
}

sf::Vector2f Character::getPosition() const {
    return sprite.getPosition();
}

float Character::getWidth() const {
    return sprite.getGlobalBounds().size.x;
}

float Character::getHeight() const {
    return sprite.getGlobalBounds().size.y;
}


void Character::handleInput() {
    if (clock.getElapsedTime().asMilliseconds() > flapCooldownInMs) {
        if (isKeyPressed(sf::Keyboard::Key::Space)) {
            velocity = flapStrength;
            clock.restart();
        }
    }
}

void Character::handleGravity(const float deltaTime) {
    velocity += gravity * deltaTime;
    sprite.move(sf::Vector2f(0, velocity * deltaTime));
}
