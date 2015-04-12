#ifndef Entity_H_
#define Entity_H_

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Entity
{
protected:
// Protected Enumerator
    enum Side { PLAYER, ENEMY, NEUTRAL };
private:
// Private Data Members
    sf::RectangleShape mShape;
    Side               mSide;
    float              mSpeed;
    sf::Vector2f       mVelocity;

    bool               mVisible;
protected:
// Protected Methods
    // Setters
    inline const void setSide(const Side& side) { mSide = side; }

public:
// Constructor / Destructor
    Entity();
    virtual ~Entity() = 0;
// Public Methods
    virtual const void update(const sf::Time& dt);
    // Setters
    inline const void setSpeed(const float speed) { mSpeed = speed; }
    inline const void setVelocity(const sf::Vector2f& vel) { mVelocity = vel; }
    inline const void setVisible(const bool status) { mVisible = status; }
    // Getters
    inline sf::RectangleShape& getShape() { return mShape; }
    inline const float getSpeed() const { return mSpeed; }
    inline const sf::Vector2f& getVelocity() const { return mVelocity; }
    inline const bool getVisible() const { return mVisible; }
};

#endif // Entity_H_
