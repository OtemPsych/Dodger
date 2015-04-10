#ifndef World_H_
#define World_H_

#include "TextHolder.h"
#include "Player.h"
#include "Enemy.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class World :private sf::NonCopyable
{
private:
// Private Data Members
    std::vector<Player> mPlayers;
    std::vector<Enemy>  mEnemies;

    unsigned short      mPlayerBase;
    unsigned short      mMaxPlayerBase;

    unsigned short      mMaxEnemyBase;

    TextHolder          mTextHolder;
    sf::RenderWindow&   mWindow;

// Private Methods
    const void addEnemies();
    const void recycleEnemies();
    const void addPlayers();

    const void resetGame();
    const void loadTexts();

public:
// Constructor
    explicit World(sf::RenderWindow& window);
// Public Methods
    const void handleInput(const sf::Keyboard::Key& key, const bool isPressed);
    const void handleCollision();
    const void update(const sf::Time& dt);
    const void draw();

};
#endif // World_H_
