#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::instance;

//Menu State code
void MenuState::Init(Game* game)
{
    title = sf::Text("Super Yams !", *(game->GetFont()), 80);
    title.setPosition(sf::Vector2f(125, 80));
    title.setStyle(sf::Text::Underlined | sf::Text::Bold);

    playButton = Button(sf::Text("Play", *(game->GetFont()), 28), sf::Vector2f(350, 50), sf::Color(124, 194, 196), sf::Color(87, 227, 195), sf::Color(164, 202, 197), [game] {
        game->PushState(PlayState::Instance());
    });
    playButton.Move(sf::Vector2f(225, 250));
}

void MenuState::Update(Game* game, sf::RenderWindow* window)
{
    //We need to fix position to local coordinates of window - 31 to remove window "bar" height
    playButton.Update(sf::Mouse::getPosition() - window->getPosition() - sf::Vector2i(0, 31));
}

void MenuState::Render(Game* game, sf::RenderWindow* window)
{
    window->draw(title);
    playButton.Render(window);
}