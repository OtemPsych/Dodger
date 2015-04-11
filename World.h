#ifndef World_H_
#define World_H_

#include "TextHolder.h"
#include "Player.h"
#include "Enemy.h"
#include "Power-Ups.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class World :private sf::NonCopyable
{
private:
// Private Data Members
    std::vector<Player>    mPlayers;
    unsigned short         mPlayerBase;
    unsigned short         mMaxPlayerBase;

    std::vector<Enemy>     mEnemies;
    unsigned short         mMaxEnemyBase;

    std::vector<Power_Ups> mPowerUps;

    TextHolder          mTextHolder;
    sf::RenderWindow&   mWindow;

// Private Methods
    const void addPlayers();
    const void addEnemies();
    const void recycleEnemies();
    const void addPowerUps();
    const void recyclePowerUps();

    const void resetGame();
    const void loadTexts();

public:
// Constructor
    explicit World(sf::RenderWindow& window);
// Public Methods
    const void handleInput(const sf::Keyboard::Key& key, const bool isPressed);
    const void handleCollision(const sf::Time& dt);
    const void update(const sf::Time& dt);
    const void draw();

};
#endif // World_H_
