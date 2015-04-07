#include "Game.h"

#include <SFML/Window/Event.hpp>

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

// Constructor
Game::Game()
    : mWindow(sf::VideoMode(1024, 768), "Dodger", sf::Style::Close
                                                | sf::Style::Titlebar)
    , mWorld(mWindow)
{
    mWindow.setFramerateLimit(700);
}

// Private Methods
    // Process Events
const void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
        switch(event.type)
        {
        case sf::Event::KeyPressed:
            handleInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handleInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
        }
}
    // Handle Input
const void Game::handleInput(const sf::Keyboard::Key& key, const bool isPressed)
{
    mWorld.handleInput(key, isPressed);
}
    // Update
const void Game::update(const sf::Time& dt)
{
    mWorld.update(dt);
}
    // Render
const void Game::render()
{
    mWindow.clear();
    mWorld.draw();
    mWindow.display();
}

// Public Method
    // Run
const void Game::run()
{
    sf::Clock clock;
    sf::Time TimeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        TimeSinceLastUpdate += clock.restart();
        while (TimeSinceLastUpdate > TimePerFrame)
        {
            TimeSinceLastUpdate -= TimePerFrame;
            processEvents();
            mWorld.handleCollision();
            update(TimePerFrame);
        }
        render();
    }
}
