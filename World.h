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

    short               mPlayerBase;

    TextHolder          mTextHolder;
    sf::RenderWindow&   mWindow;

public:
// Constructor
    explicit World(sf::RenderWindow& window);
// Public Methods
    const void addEnemies();
    const void recycleEnemies();

    const void addPlayers();

    const void handleInput(const sf::Keyboard::Key& key, const bool isPressed);
    const void handleCollision();
    const void resetGame();
    const void update(const sf::Time& dt);
    const void draw();

    const void loadTexts();
};
#endif // World_H_
