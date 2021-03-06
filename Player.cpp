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
Player::Player(sf::Text& text, const sf::Vector2f& relTextPos, const sf::Vector2f& worldBounds)
    : Entity()
    , mScore(0)
    , mScoreText(text)
{
// Shape
    float Size = 45.f;
    getShape().setSize(sf::Vector2f(Size, Size));
    getShape().setPosition(sf::Vector2f(worldBounds.x / 2 - getShape().getSize().x / 2,
                                        worldBounds.y - getShape().getSize().y - 10.f));

// Side
    setSide(PLAYER);
// Velocity
    setSpeed(475.f);
    setVelocity(sf::Vector2f(getSpeed(), getSpeed()));
// Movement
    mMovement.UP = mMovement.DOWN
    = mMovement.LEFT = mMovement.RIGHT = false;
// Relative Text
    setRelativeTextPosition(relTextPos);
    mScoreText.setColor(getShape().getFillColor());
}

// Private Methods
    // Update Score
const void Player::updateScore()
{
    if (getVisible()) {
        mScore += 1;
        mScoreText.setString("Score: " + NumberToString(mScore));
    }
}
    // Set Relative Text Position
const void Player::setRelativeTextPosition(const sf::Vector2f& relText) const
{
     mScoreText.setPosition(sf::Vector2f(relText.x,
                                         relText.y - 30.f));
}

// Public Methods
    // Handle Collision
const bool Player::handleCollision(std::vector<Power_Ups>& powers,
                                   std::vector<Enemy>& enemies,
                                   const sf::Vector2f& worldBounds,
                                   const sf::Time& dt)
{
// Wall Collision
    if (getShape().getPosition().y < 0.f)
        mMovement.UP = false;
    else if (getShape().getPosition().y + getShape().getSize().y > worldBounds.y)
        mMovement.DOWN = false;
    if (getShape().getPosition().x < 0.f)
        mMovement.LEFT = false;
    else if (getShape().getPosition().x + getShape().getSize().x > worldBounds.x)
        mMovement.RIGHT = false;

// Entity Collision
    for (unsigned i = 0; i < (enemies.size() > powers.size() ? enemies.size()
                                                             : powers.size()); i++) {
        if (powers.begin()+i < powers.end() && powers[i].getVisible())
            if (getShape().getPosition().x < powers[i].getShape().getPosition().x + powers[i].getShape().getSize().x
             && getShape().getPosition().x + getShape().getSize().x > powers[i].getShape().getPosition().x
             && getShape().getPosition().y < powers[i].getShape().getPosition().y + powers[i].getShape().getSize().y
             && getShape().getPosition().y + getShape().getSize().y > powers[i].getShape().getPosition().y) {
                if (powers[i].getType() == Power_Ups::SLOW)
                    powers[i].usePower(enemies, dt);
                powers[i].setVisible(false);
            }

        if (enemies.begin()+i < enemies.end() && enemies[i].getVisible())
            if (getShape().getPosition().x < enemies[i].getShape().getPosition().x + enemies[i].getShape().getSize().x
             && getShape().getPosition().x + getShape().getSize().x > enemies[i].getShape().getPosition().x
             && getShape().getPosition().y < enemies[i].getShape().getPosition().y + enemies[i].getShape().getSize().y
             && getShape().getPosition().y + getShape().getSize().y > enemies[i].getShape().getPosition().y)
                return true;
    }

    return false;
}
    // Update
const void Player::update(const sf::Time& dt)
{
    sf::Vector2f movement(0.f, 0.f);

    if (mMovement.UP)
        movement.y -= getSpeed();
    if (mMovement.DOWN)
        movement.y += getSpeed();
    if (mMovement.LEFT)
        movement.x -= getSpeed();
    if (mMovement.RIGHT)
        movement.x += getSpeed();

    setVelocity(movement);
    Entity::update(dt);

    updateScore();
}
