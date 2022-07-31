#include <SFML/Graphics.hpp>

#include "Game.h"
#include "MenuState.h"

int main()
{
    Game game;
    game.ChangeState(MenuState::Instance());
    game.run();
    return 0;
}