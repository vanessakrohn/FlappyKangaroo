#include "Game.h"

Game::Game() : window(sf::VideoMode({width, height}), "Flappy SFML Project"),
               character({static_cast<float>(width) * 0.33f, static_cast<float>(height) * 0.5f}),
               pipes(character) {
}

void Game::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        isGameOver = isGameOver || character.isOutsideWindow(window);
        if (!isGameOver) {
            const float deltaTime = clock.restart().asSeconds();
            character.update(deltaTime);
            points.update(deltaTime);
            isGameOver = pipes.update(deltaTime);
        }

        window.clear();
        background.draw(window);
        pipes.draw(window);
        points.draw(window);
        character.draw(window);

        if (isGameOver) {
            gameOver.draw(window);
        }

        window.display();
    }
}
