#include "PlayState.h"

PlayState PlayState::instance;

void PlayState::Init(Game* game)
{
    text = sf::Text("Playing game:", *(game->GetFont()), 80);
    text.setPosition(sf::Vector2f(125, 80));
    text.setStyle(sf::Text::Underlined | sf::Text::Bold);

    button = Button(sf::Text("Back", *(game->GetFont()), 28), sf::Vector2f(200, 100), sf::Color(124, 194, 196), sf::Color(87, 227, 195), sf::Color(164, 202, 197), [game] {
        game->PopState();
    });
    button.Move(sf::Vector2f(50, 425));
}

void PlayState::Update(Game* game, sf::RenderWindow* window)
{
    button.Update(sf::Mouse::getPosition() - window->getPosition() - sf::Vector2i(0, 31));
}

void PlayState::Render(Game* game, sf::RenderWindow* window)
{
    window->draw(text);
    button.Render(window);
}