#ifndef Player_H_
#define Player_H_

#include "Enemy.h"

#include <SFML/Graphics/Text.hpp>

class Player :public Entity
{
private:
// Private Data Members
    struct movement{
        bool UP,
             DOWN,
             LEFT,
             RIGHT;
    }         mMovement;
    float     mSpeed;
    long      mScore;
    sf::Text& mScoreText;

// Private Method
    const void setRelativeTextPosition(const sf::Vector2f& relText) const;

public:
// Constructor
    Player(sf::Text& text, const sf::Vector2f& relTextPos, const sf::Vector2f& worldBounds);
// Public Methods
    const void handleCollision(const sf::Vector2f& worldBounds);
    const bool handleCollision(std::vector<Enemy>& enemies);
    virtual const void update(const sf::Time& dt);
    const void updateScore();

    // Getters
    inline const sf::Text& getScoreText() const { return mScoreText; }
    inline movement& getMovement() { return mMovement; }
};
#endif // Player_H_
