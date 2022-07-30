#include "GameState.h"
#include <iostream>

MenuState MenuState::instance;

//Menu State code
void MenuState::Init(Game* game)
{
    title = sf::Text("Super Yams !", *(game->GetFont()), 80);
    title.setPosition(sf::Vector2f(125, 80));
    title.setStyle(sf::Text::Underlined | sf::Text::Bold);

    button = Button(sf::Text("Button man", *(game->GetFont()), 28), sf::Vector2f(200, 100), sf::Color::Green, sf::Color::Red, sf::Color::Yellow, [] { std::cout << "Wesh mon frere t'es trop fort en c++ la" << std::endl; });
    button.Move(sf::Vector2f(100, 300));
}

void MenuState::Update(Game* game, sf::RenderWindow* window)
{
    //We need to fix position to local coordinates of window - 31 to remove window "bar" height
    button.Update(sf::Mouse::getPosition() - window->getPosition() - sf::Vector2i(0, 31));
}

void MenuState::Render(Game* game, sf::RenderWindow* window)
{
    window->draw(title);
    button.Render(window);
}