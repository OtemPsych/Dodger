#include "Player.h"

#include <sstream>

template <typename T>
std::string NumberToString(T num)
{
    std::ostringstream temp;
    temp << num;
    return temp.str();
}
// Constructor
Player::Player(const sf::Vector2f& worldBounds)
    : Entity()
    , mSpeed(475.f)
    , mScore(0)
{
// Shape
    float Size = 45.f;
    getShape().setSize(sf::Vector2f(Size, Size));
    resetPosition(worldBounds);

    getShape().setFillColor(sf::Color::Green);

// Side
    setSide(PLAYER);

// Velocity
    setVelocity(sf::Vector2f(mSpeed, mSpeed));
// Movement
    mMovement.UP = mMovement.DOWN
    = mMovement.LEFT = mMovement.RIGHT = false;
}

// Public Methods
    // Handle Collision
const void Player::handleCollision(const sf::Vector2f& worldBounds)
{
    if (getShape().getPosition().y < 0.f)
        mMovement.UP = false;
    else if (getShape().getPosition().y + getShape().getSize().y > worldBounds.y)
        mMovement.DOWN = false;
    if (getShape().getPosition().x < 0.f)
        mMovement.LEFT = false;
    else if (getShape().getPosition().x + getShape().getSize().x > worldBounds.x)
        mMovement.RIGHT = false;
}
    // Handle Collision
const bool Player::handleCollision(std::vector<Enemy>& enemies)
{
// Entity Collision
    for (unsigned i = 0; i < enemies.size(); i++)
        if (getShape().getPosition().x < enemies[i].getShape().getPosition().x + enemies[i].getShape().getSize().x
         && getShape().getPosition().x + getShape().getSize().x > enemies[i].getShape().getPosition().x
         && getShape().getPosition().y < enemies[i].getShape().getPosition().y + enemies[i].getShape().getSize().y
         && getShape().getPosition().y + getShape().getSize().y > enemies[i].getShape().getPosition().y)
            return true;

    return false;
}
    // Update
const void Player::update(const sf::Time& dt)
{
    if (getShape().getFillColor().a != 0.f)
        mScore += 1;

    sf::Vector2f movement(0.f, 0.f);

    if (mMovement.UP)
        movement.y -= mSpeed;
    if (mMovement.DOWN)
        movement.y += mSpeed;
    if (mMovement.LEFT)
        movement.x -= mSpeed;
    if (mMovement.RIGHT)
        movement.x += mSpeed;

    setVelocity(movement);
    Entity::update(dt);
}
    // Reset Position
const void Player::resetPosition(const sf::Vector2f& worldBounds)
{
    getShape().setPosition(sf::Vector2f(worldBounds.x / 2 - getShape().getSize().x / 2,
                                        worldBounds.y - getShape().getSize().y - 10.f));
}
    // Score Text
const std::string Player::getScoreText() const
{
    return "Score: " + NumberToString(mScore);
}