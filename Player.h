#ifndef Player_H_
#define Player_H_

#include "Enemy.h"
#include "Power-Ups.h"

#include <memory>

#include <SFML/Graphics/Text.hpp>

class Power_Ups;
class Player :public Entity
{
private:
// Private Data Members
    struct movement{
        bool UP,
             DOWN,
             LEFT,
             RIGHT;
    }          mMovement;
    long       mScore;
    sf::Text&  mScoreText;

// Private Methods
    const void updateScore();
    const void setRelativeTextPosition(const sf::Vector2f& relText) const;

public:
// Constructor
    Player(sf::Text& text, const sf::Vector2f& relTextPos, const sf::Vector2f& worldBounds);
// Public Methods
    const bool handleCollision(std::vector<Power_Ups>& powers,
                               std::vector<Enemy>& enemies,
                               const sf::Vector2f& worldBounds,
                               const sf::Time& dt);
    virtual const void update(const sf::Time& dt);
    // Getters
    inline const sf::Text& getScoreText() const { return mScoreText; }
    inline movement& getMovement() { return mMovement; }
};
#endif // Player_H_
