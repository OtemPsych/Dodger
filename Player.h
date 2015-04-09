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

public:
// Constructor
    Player(sf::Text& text, const sf::Vector2f& worldBounds);
// Public Methods
    const void handleCollision(const sf::Vector2f& worldBounds);
    const bool handleCollision(std::vector<Enemy>& enemies);
    virtual const void update(const sf::Time& dt);
    const void updateScoreText();
    const void resetPosition(const sf::Vector2f& worldBounds);

    // Getter
    inline movement& getMovement() { return mMovement; }
};
#endif // Player_H_
