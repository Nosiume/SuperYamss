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
	virtual void Update(Game* game) = 0;
	virtual void Render(Game* game, sf::RenderWindow*) = 0;

	void ChangeState(Game* game, GameState* state)
	{
		game->ChangeState(state);
	}

protected:
	GameState() {}
};


class MenuState : public GameState
{
private:
	sf::Text title;

public:
	void Init(Game*);
	void CleanUp() {  }; //Empty, for now

	void Pause() {}; //Emptyyyyyy
	void Resume() {}; //Same here

	void HandleEvents(Game*) {} // Nothing to see here
	void Update(Game*);
	void Render(Game*, sf::RenderWindow*);

	static MenuState* Instance()
	{
		return &instance;
	}

private:
	static MenuState instance;
};


