#include "Power-Ups.h"

// Constructor
Power_Ups::Power_Ups(const Type& type, const sf::Vector2f& worldBounds)
    : Entity()
    , mType(type)
{
// Shape
    // Size
    float Size = 15.f;
    getShape().setSize(sf::Vector2f(Size, Size));
    // Position
    float xPos = (float)rand() / RAND_MAX * (worldBounds.x - Size);
    float yPos = (float)rand() / RAND_MAX * (worldBounds.y - Size);
    getShape().setPosition(sf::Vector2f(xPos, yPos));

    getShape().setFillColor(sf::Color::Black);
    getShape().setOutlineThickness(5.f);
    getShape().setOutlineColor(sf::Color::Cyan);

// Side
    setSide(NEUTRAL);

// Velocity
    setVelocity(sf::Vector2f(0.f, 130.f));
}

// Public Methods
    // Update
const void Power_Ups::update(const sf::Time& dt)
{
    getShape().rotate(3.f);
    Entity::update(dt);
}
    // Use Power
const void Power_Ups::usePower(std::vector<Enemy>& enemies, const sf::Time& dt)
{
    for (unsigned i = 0; i < enemies.size(); i++)
        if (enemies[i].getVelocity().y == enemies[i].getSpeed())
            enemies[i].setVelocity(sf::Vector2f(0.f, enemies[i].getSpeed() / 2));
    update(dt);
}

