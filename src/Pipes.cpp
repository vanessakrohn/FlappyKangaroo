#include "Pipe.h"
#include "Pipes.h"
#include <random>

enum class PipeType {
    Top = 0,
    Bottom = 1
};

Pipe createRandomPipe() {
    std::random_device rd;
    std::uniform_int_distribution typeDist(0, 1);
    std::uniform_int_distribution heightDist(100, 700);
    const auto type = static_cast<PipeType>(typeDist(rd));
    const auto height = static_cast<float>(heightDist(rd));

    if (type == PipeType::Top) {
        return {
            ResourceManager::getInstance().topPipeTexture,
            sf::Vector2f(1920.f, 0.f),
            height
        };
    }

    return {
        ResourceManager::getInstance().bottomPipeTexture,
        sf::Vector2f(1920.f, 1080.f - height),
        height
    };
}

bool Pipes::update(const float deltaTime) {
    periodicallySpawnPipe(deltaTime);
    movePipes();
    return collisionDetection();
}

void Pipes::draw(sf::RenderWindow &window) const {
    for (auto &pipe: pipesBeforeCharacter) {
        pipe.draw(window);
    }

    for (auto &pipe: pipesAfterCharacter) {
        pipe.draw(window);
    }
}

void Pipes::periodicallySpawnPipe(const float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime >= 1.f) {
        const Pipe pipe = createRandomPipe();
        pipesBeforeCharacter.push_back(pipe);
        elapsedTime -= 1.f;
    }
}

void Pipes::movePipes() {
    for (auto &pipe: pipesBeforeCharacter) {
        pipe.move(-scrollSpeed);
    }

    for (auto &pipe: pipesAfterCharacter) {
        pipe.move(-scrollSpeed);
    }
}

bool Pipes::collisionDetection() {
    bool isGameOver = false;
    while (!pipesBeforeCharacter.empty() && pipesBeforeCharacter.front().getPosition().x + pipesBeforeCharacter.
           front().getWidth() < character.getPosition().x) {
        pipesAfterCharacter.push_back(pipesBeforeCharacter.front());
        pipesBeforeCharacter.pop_front();
    }

    if (!pipesBeforeCharacter.empty()) {
        const Pipe maybeCollisionPipe = pipesBeforeCharacter.front();
        if (maybeCollisionPipe.intersects(character.getCollisionBox())) {
            isGameOver = true;
        }
    }

    while (!pipesAfterCharacter.empty() && pipesAfterCharacter.front().getPosition().x + pipesAfterCharacter.
           front().getWidth() < 0.f) {
        pipesAfterCharacter.pop_front();
    }
    return isGameOver;
}
