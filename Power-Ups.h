#ifndef Power_Ups_H_
#define Power_Ups_H_

#include "Player.h"

#include <SFML/System/Time.hpp>

class Power_Ups :public Entity
{
public:
// Public Enumerator
    enum Type { SLOW, INVULNERABILITY };
private:
// Private Data Members
    Type     mType;
    sf::Time mPowerDuration;

public:
// Constructor
    Power_Ups(const Type& type, const sf::Vector2f& worldBounds);
// Public Methods
    virtual const void update(const sf::Time& dt);
    // Setter
    inline const void setPowerDuration(const sf::Time& sec) { mPowerDuration = sec; }
    // Getters
    inline const Type& getType() const { return mType; }
    inline const sf::Time& getPowerDuration() const { return mPowerDuration; }
};
#endif // Power_Ups_H_
