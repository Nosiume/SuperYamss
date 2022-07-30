#include "Game.h"
#include "GameState.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Super Yamssss");
    window.setVerticalSyncEnabled(true); // Since nowadays you can see 360hz monitor
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(54, 108, 194, 255));
        
        //Render
        states.back()->Update(this, &window);
        states.back()->Render(this, &window);

        window.display();
    }
}

void Game::ChangeState(GameState* state)
{
    if (!states.empty())
    {
        states.back()->CleanUp();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Init(this);
}

void Game::PushState(GameState* state)
{
    if (!states.empty())
        states.back()->Pause();

    states.push_back(state);
    states.back()->Init(this);
}

void Game::PopState()
{
    if (!states.empty())
    {
        states.back()->CleanUp();
        states.pop_back();
    }
    
    //redo the check since one state was popped on previous condition
    if (!states.empty())
        states.back()->Resume();
}

//Constructors and destructors
Game::Game()
{
    //Load fonts
    if (!font.loadFromFile("assets/font.ttf"))
    {
        MessageBox(NULL, TEXT("Failed to load game font"), TEXT("Error !"), MB_OK | MB_ICONERROR);
        exit(-1);
    }
}

Game::~Game()
{

}