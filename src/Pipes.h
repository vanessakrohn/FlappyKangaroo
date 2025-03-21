#ifndef PIPES_H
#define PIPES_H

#include "Character.h"
#include "Pipe.h"
#include "ResourceManager.h"

class Pipes {
public:
    explicit Pipes(Character &character): character(character) {
    }

    bool update(float deltaTime);
    void draw(sf::RenderWindow &window) const;

private:
    Character &character;
    std::deque<Pipe> pipesBeforeCharacter;
    std::deque<Pipe> pipesAfterCharacter;

    float scrollSpeed = 0.15;
    float elapsedTime = 0;
    float collisionDeadZone = 20;


    void periodicallySpawnPipe(float deltaTime);
    void movePipes();
    bool collisionDetection();
};

#endif
