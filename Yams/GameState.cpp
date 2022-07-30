#include "GameState.h"
#include <iostream>

MenuState MenuState::instance;

//Menu State
void MenuState::Init(Game* game)
{
    std::cout << "Initializing menu state" << std::endl;
    title = sf::Text("Super Yams !", game->GetFont(), 80);
    title.setPosition(sf::Vector2f(125, 80));
    title.setStyle(sf::Text::Underlined | sf::Text::Bold);
}

void MenuState::Update(Game* game)
{

}

void MenuState::Render(Game* game, sf::RenderWindow* window)
{
    window->draw(title);
}