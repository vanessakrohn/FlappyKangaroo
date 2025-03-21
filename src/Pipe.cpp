#include "Pipe.h"

Pipe::Pipe(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &startPosition, const float height)
    : texture(texture), sprite(*texture) {
    sprite.setPosition(startPosition);

    const sf::Vector2f desiredSize(150.f, height);
    const sf::Vector2u textureSize = texture->getSize();
    const sf::Vector2f scaleFactors(
        desiredSize.x / static_cast<float>(textureSize.x),
        desiredSize.y / static_cast<float>(textureSize.y));
    sprite.setScale(scaleFactors);
}

void Pipe::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

void Pipe::move(const float deltaX) {
    sprite.move(sf::Vector2f(deltaX, 0.f));
}

sf::Vector2f Pipe::getPosition() const {
    return sprite.getPosition();
}

float Pipe::getWidth() const {
    return sprite.getGlobalBounds().size.x;
}

float Pipe::getHeight() const {
    return sprite.getGlobalBounds().size.y;
}

bool Pipe::intersects(const sf::FloatRect &other) const {
    return sprite.getGlobalBounds().findIntersection(other).has_value();
}
