#include "Entity.h"

// Constructor
Entity::Entity()
{
    // General Properties
    mShape.setOrigin(mShape.getLocalBounds().height / 2,
                     mShape.getLocalBounds().width / 2);

    int red = rand() % 256,
        green = rand() % 256,
        blue = rand() % 256;
    mShape.setFillColor(sf::Color(red, green, blue));
    mShape.setOutlineThickness(2.f);
    mShape.setOutlineColor(sf::Color::White);
}

// Destructor
Entity::~Entity()
{
}

// Public Method
    // Update
const void Entity::update(const sf::Time& dt)
{
    mShape.move(mVelocity * dt.asSeconds());
}
