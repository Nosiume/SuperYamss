#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>

class GameState; // Required otherwise compiler and linker will do shit

class Game
{
private:
	//Game states stack
	std::vector<GameState*> states;

	sf::Font font;
	bool running = true;

public:
	Game();
	~Game();

	void run();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	sf::Font* GetFont() { return &font; }
};