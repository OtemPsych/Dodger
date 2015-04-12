#ifndef Power_Ups_H_
#define Power_Ups_H_

#include "Player.h"
#include "Enemy.h"

#include <SFML/System/Time.hpp>

class Player;
class Power_Ups :public Entity
{
public:
// Public Enumerator
    enum Type { SLOW };
private:
// Private Data Member
    Type     mType;

public:
// Constructor
    Power_Ups(const Type& type, const sf::Vector2f& worldBounds);
// Public Methods
    virtual const void update(const sf::Time& dt);
    const void usePower(std::vector<Enemy>& enemies, const sf::Time& dt);
    // Getter
    inline const Type& getType() const { return mType; }
};
#endif // Power_Ups_H_
