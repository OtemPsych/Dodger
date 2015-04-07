#ifndef Entity_H_
#define Entity_H_

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Entity
{
protected:
// Protected Enumerator
    enum Side { PLAYER, ENEMY };
private:
// Private Data Members
    sf::RectangleShape mShape;
    Side               mSide;
    sf::Vector2f       mVelocity;
protected:
// Protected Methods
    // Setters
    inline const void setSide(const Side& side) { mSide = side; }
    inline const void setVelocity(const sf::Vector2f& vel) { mVelocity = vel; }

public:
// Constructor / Destructor
    Entity();
    virtual ~Entity() = 0;
// Public Methods
    virtual const void update(const sf::Time& dt) = 0;
    // Getter
    inline sf::RectangleShape& getShape() { return mShape; }
};

#endif // Entity_H_
