#include "TextHolder.h"

#include <stdexcept>

// Constructor
TextHolder::TextHolder()
    : mTextHolder()
    , mFont()
{
    if (!mFont.loadFromFile("Media/Sansation.ttf"))
        if (!mFont.loadFromFile("Media/Coolvetica.ttf"))
            throw std::runtime_error("TextHolder::TextHolder() - Failed to load font");
}

// Public Methods
    // Load
const void TextHolder::load(const Texts::ID& id, const std::string& str,
                            const unsigned charSize, const sf::Vector2f& pos,
                            const sf::Color& color)
{
    std::unique_ptr<sf::Text> text(new sf::Text());

    text->setFont(mFont);
    text->setString(str);
    text->setCharacterSize(charSize);
    text->setColor(color);
    text->setOrigin(text->getLocalBounds().width / 2,
                    text->getLocalBounds().height / 2);
    text->setPosition(pos);
    text->setScale(1.1f, 1.1f);

    if (mTextHolder.find(id) == mTextHolder.end()) {
        std::vector<std::unique_ptr<sf::Text>> newVector;
        mTextHolder.insert(std::make_pair(id, std::move(newVector)));
    }
    mTextHolder[id].push_back(std::move(text));
}
    // Get
sf::Text& TextHolder::get(const Texts::ID& id, const unsigned pos) const
{
    return *mTextHolder.find(id)->second[pos];
}
    // Fade Text
const void TextHolder::fadeText(sf::Text& text, const float rate) const
{
    if (text.getColor().a > 0.f)
        text.setColor(sf::Color(text.getColor().r,
                                text.getColor().g,
                                text.getColor().b,
                                (text.getColor().a - rate) >= 0.f ? text.getColor().a - rate
                                                                  : 0.f));
}
    // Correct Properties
const void TextHolder::correctProperties(sf::Text& text) const
{
    text.setOrigin(text.getLocalBounds().width / 2,
                   text.getLocalBounds().height /2);

    text.setColor(sf::Color(text.getColor().r,
                            text.getColor().g,
                            text.getColor().b,
                            255.f));
}
