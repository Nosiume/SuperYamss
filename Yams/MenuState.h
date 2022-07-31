#pragma once

#include "GameState.h"
#include "Button.h"

class MenuState : public GameState
{
private:
	sf::Text title;
	Button playButton;

public:
	void Init(Game*);
	void CleanUp() {  }; //Empty, for now

	void Pause() {}; //Emptyyyyyy
	void Resume() {}; //Same here

	void HandleEvents(Game*) {} // Nothing to see here
	void Update(Game*, sf::RenderWindow*);
	void Render(Game*, sf::RenderWindow*);

	static MenuState* Instance()
	{
		return &instance;
	}

private:
	static MenuState instance;
};


