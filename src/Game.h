#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Pipes.h"
#include "Background.h"
#include "GameOver.h"
#include "Points.h"

class Game {
public:
    Game();
    void run();
private:
    unsigned width = 1920;
    unsigned height = 1080;
    bool isGameOver = false;

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Clock clockPipe;

    Background background;
    Character character;
    GameOver gameOver;
    Points points;
    Pipes pipes;
};

#endif
