#include "Enemy.h"

// Constructor
Enemy::Enemy(const sf::Vector2f& worldBounds)
    : Entity()
{
// Shape
    // Size
    float maxSize = 70.f;
    float minSize = 15.f;
    float Size = (float)rand() / RAND_MAX * (maxSize - minSize) + minSize;
    getShape().setSize(sf::Vector2f(Size, Size));

    // Position
    float xPos = (float)rand() / RAND_MAX * (worldBounds.x - Size);
    float yPos = -Size - 55.f;
    getShape().setPosition(sf::Vector2f(xPos, yPos));

// Side
    setSide(ENEMY);

// Speed / Velocity
    float maxYVel = 600.f;
    float minYVel = 250.f;
    float yVel = (float)rand() / RAND_MAX * (maxYVel - minYVel) + minYVel;
    setSpeed(yVel);
    setVelocity(sf::Vector2f(0.f, yVel));
}
