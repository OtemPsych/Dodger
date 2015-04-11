#include "World.h"

// Constructor
World::World(sf::RenderWindow& window)
    : mPlayers()
    , mPlayerBase(1)
    , mMaxPlayerBase(40)
    , mEnemies()
    , mMaxEnemyBase(25)
    , mTextHolder()
    , mWindow(window)
{
    loadTexts();
    addPlayers();
}

// Private Methods
    // Add Players
const void World::addPlayers()
{
    const sf::Vector2f leftPosition(85.f, mWindow.getSize().y - 30.f);
    const sf::Vector2f rightPosition(mWindow.getSize().x - leftPosition.x, leftPosition.y);

    for (short i = mPlayers.size(); i < mPlayerBase; i++) {
        Player player(mTextHolder.get(Texts::Scores, i),
                      (i % 2 == 0 ? (i > 0 ? mPlayers[i-2].getScoreText().getPosition()
                                           : leftPosition)
                                  : (i > 1 ? mPlayers[i-2].getScoreText().getPosition()
                                           : rightPosition)),
                      sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y));
        mPlayers.push_back(std::move(player));
    }
}
    // Add Enemies
const void World::addEnemies()
{
    if (mEnemies.size() < mMaxEnemyBase) {
        Enemy newEnemy(sf::Vector2f(mWindow.getSize().x, mWindow.getSize().y));
        mEnemies.push_back(std::move(newEnemy));
    }
}
    // Recycle Enemies
const void World::recycleEnemies()
{
    for (unsigned i = 0; i < mEnemies.size(); i++)
        if (mEnemies[i].getShape().getPosition().y > mWindow.getSize().y)
            mEnemies.erase(mEnemies.begin()+i);
}
    // Add Power Ups
const void World::addPowerUps()
{
    int chance = rand() % 5000;
    if (chance < 20) {
        Power_Ups newPowerUp((chance < 2 ? Power_Ups::INVULNERABILITY
                                         : Power_Ups::SLOW), sf::Vector2f(mWindow.getSize()));
        mPowerUps.push_back(std::move(newPowerUp));
    }
}
    // Recycle Power Ups
const void World::recyclePowerUps()
{
    for (unsigned i = 0; i < mPowerUps.size(); i++)
        if (mPowerUps[i].getShape().getPosition().y > mWindow.getSize().y)
            mPowerUps.erase(mPowerUps.begin()+i);
}
    // Reset Game
const void World::resetGame()
{
    mPlayers.clear();
    addPlayers();
    mEnemies.clear();
    mPowerUps.clear();
}
    // Load Texts
const void World::loadTexts()
{
    for (unsigned i = 0; i < mMaxPlayerBase; i++)
        mTextHolder.load(Texts::Scores, "", 25.f,
                         sf::Vector2f(0.f, 0.f), sf::Color::White);
}

// Public Methods
    // Handle Input
const void World::handleInput(const sf::Keyboard::Key& key, const bool isPressed)
{
// Add Players
    if (isPressed) {
        if (key == sf::Keyboard::Return)
            if (mPlayerBase < mMaxPlayerBase) {
                mPlayerBase++;
                resetGame();
            }
        if (key == sf::Keyboard::BackSpace)
            if (mPlayerBase > 1) {
                mPlayerBase--;
                mPlayers.pop_back();
                resetGame();
            }
    }

// Player 1
    if (mPlayers.size() > 0) {
        if (key == sf::Keyboard::W)
            mPlayers[0].getMovement().UP = isPressed;
        else if (key == sf::Keyboard::S)
            mPlayers[0].getMovement().DOWN = isPressed;
        else if (key == sf::Keyboard::A)
            mPlayers[0].getMovement().LEFT = isPressed;
        else if (key == sf::Keyboard::D)
            mPlayers[0].getMovement().RIGHT = isPressed;
    }
// Player 2
    if (mPlayers.size() > 1) {
        if (key == sf::Keyboard::Up)
            mPlayers[1].getMovement().UP = isPressed;
        else if (key == sf::Keyboard::Down)
            mPlayers[1].getMovement().DOWN = isPressed;
        else if (key == sf::Keyboard::Left)
            mPlayers[1].getMovement().LEFT = isPressed;
        else if (key == sf::Keyboard::Right)
            mPlayers[1].getMovement().RIGHT = isPressed;
    }
// Player 3
    if (mPlayers.size() > 2) {
        if (key == sf::Keyboard::Numpad5)
            mPlayers[2].getMovement().UP = isPressed;
        else if (key == sf::Keyboard::Numpad2)
            mPlayers[2].getMovement().DOWN = isPressed;
        else if (key == sf::Keyboard::Numpad1)
            mPlayers[2].getMovement().LEFT = isPressed;
        else if (key == sf::Keyboard::Numpad3)
            mPlayers[2].getMovement().RIGHT = isPressed;
    }
// Player 4
    if (mPlayers.size() > 3) {
        if (key == sf::Keyboard::I)
            mPlayers[3].getMovement().UP = isPressed;
        else if (key == sf::Keyboard::K)
            mPlayers[3].getMovement().DOWN = isPressed;
        else if (key == sf::Keyboard::J)
            mPlayers[3].getMovement().LEFT = isPressed;
        else if (key == sf::Keyboard::L)
            mPlayers[3].getMovement().RIGHT = isPressed;
    }
}
    // Handle Collision
const void World::handleCollision(const sf::Time& dt)
{
    for (unsigned i = 0; i < mPlayers.size(); i++)
        if (mPlayers[i].handleCollision(mPowerUps, mEnemies, sf::Vector2f(mWindow.getSize()), dt)) {
            mPlayers[i].getShape().setFillColor(sf::Color(mPlayers[i].getShape().getFillColor().r,
                                                          mPlayers[i].getShape().getFillColor().g,
                                                          mPlayers[i].getShape().getFillColor().b,
                                                          0.f));
            mPlayers[i].getShape().setOutlineThickness(0.f);
        }

    unsigned short totalDead = 0;
    for (unsigned i = 0; i < mPlayers.size(); i++)
        if (mPlayers[i].getShape().getFillColor().a == 0.f)
            totalDead++;

    if (totalDead == mPlayers.size()) {
        mPlayers.clear();
        resetGame();
    }
}
    // Update
const void World::update(const sf::Time& dt)
{
    for (unsigned i = 0; i < (mPlayers.size() > mEnemies.size() ? mPlayers.size()
                                                                : mEnemies.size()); i++) {
        if (mPlayers.begin()+i < mPlayers.end()) {
            mPlayers[i].update(dt);
            mTextHolder.correctProperties(mTextHolder.get(Texts::Scores, i));
        }
        if (mEnemies.begin()+i < mEnemies.end())
            mEnemies[i].update(dt);
        if (mPowerUps.begin()+i < mPowerUps.end())
            mPowerUps[i].update(dt);
    }

    addEnemies();
    recycleEnemies();
    addPowerUps();
    recyclePowerUps();
}
    // Draw
const void World::draw()
{
    for (unsigned i = 0; i < (mPlayers.size() > mEnemies.size() ? mPlayers.size()
                                                                : mEnemies.size()); i++) {
        if (mEnemies.begin()+i < mEnemies.end())
            mWindow.draw(mEnemies[i].getShape());

        if (mPlayers.begin()+i < mPlayers.end()) {
            if (mPlayers[i].getShape().getFillColor().a > 0.f)
                mWindow.draw(mPlayers[i].getShape());
            mWindow.draw(mTextHolder.get(Texts::Scores, i));
        }

        if (mPowerUps.begin()+i < mPowerUps.end())
            mWindow.draw(mPowerUps[i].getShape());
    }
}
