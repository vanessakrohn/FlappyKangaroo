#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class ResourceManager {
public:
    static ResourceManager &getInstance() {
        static ResourceManager instance; // Guaranteed to be initialized only once
        return instance;
    }

    ResourceManager(const ResourceManager &) = delete;

    ResourceManager &operator=(const ResourceManager &) = delete;

    ResourceManager(ResourceManager &&) = delete;

    ResourceManager &operator=(ResourceManager &&) = delete;

    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    std::shared_ptr<sf::Texture> characterTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> topPipeTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> bottomPipeTexture = std::make_shared<sf::Texture>();


private:
    ResourceManager() {
        if (!font->openFromFile("resources/font.ttf")) {
            std::cerr << "Failed to load font from resources/font.ttf" << std::endl;
        }

        if (!characterTexture->loadFromFile("resources/character.png")) {
            std::cerr << "Failed to load texture from resources/character.png" << std::endl;
        }

        if (!topPipeTexture->loadFromFile("resources/pipetop.png")) {
            std::cerr << "Failed to load texture from resources/pipetop.png" << std::endl;
        }

        if (!bottomPipeTexture->loadFromFile("resources/pipebottom.png")) {
            std::cerr << "Failed to load texture from resources/pipebottom.png" << std::endl;
        }
    }
};

#endif