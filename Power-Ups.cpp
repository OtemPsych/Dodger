#include "Power-Ups.h"

// Constructor
Power_Ups::Power_Ups(const Type& type, const sf::Vector2f& worldBounds)
    : Entity()
    , mType(type)
    , mPowerDuration(sf::Time::Zero)
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
    getShape().setOutlineColor(mType == INVULNERABILITY ? sf::Color(255, 215, 0)
                                                        : sf::Color::Cyan);

// Side
    setSide(NEUTRAL);

// Velocity
    setVelocity(mType == INVULNERABILITY ? sf::Vector2f(0.f, 220.f)
                                         : sf::Vector2f(0.f, 130.f));
}

// Public Method
    // Update
const void Power_Ups::update(const sf::Time& dt)
{
    getShape().rotate(3.f);
    Entity::update(dt);
}
