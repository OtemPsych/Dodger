#ifndef Enemy_H_
#define Enemy_H_

#include "Entity.h"

class Enemy :public Entity
{
public:
// Constructor
    explicit Enemy(const sf::Vector2f& worldBounds);
// Public Method
    virtual const void update(const sf::Time& dt);
};

#endif // Enemy_H_
