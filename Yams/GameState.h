#pragma once

#include "Game.h"

class GameState
{
public:
	virtual void Init(Game* game) = 0;
	virtual void CleanUp() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(Game* game) = 0;
	virtual void Update(Game* game, sf::RenderWindow* window) = 0;
	virtual void Render(Game* game, sf::RenderWindow* window) = 0;

	void ChangeState(Game* game, GameState* state)
	{
		game->ChangeState(state);
	}

protected:
	GameState() {}
};

