#ifndef Game_H_
#define Game_H_

#include "World.h"

class Game :private sf::NonCopyable
{
private:
// Private Data Members
    sf::RenderWindow mWindow;
    World            mWorld;
// Private Methods
    const void processEvents();
    const void handleInput(const sf::Keyboard::Key& key, const bool isPressed);
    const void update(const sf::Time& dt);
    const void render();

public:
// Constructor
    Game();
// Public Method
    const void run();
};
#endif // Game_H_
