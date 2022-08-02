#pragma once

#include "GameState.h"
#include "Button.h"
#include "RangeSlider.h"

class PlayState : public GameState
{
private:
	sf::Text text;
	Button button;

	RangeSlider slider;

public:
	void Init(Game*);
	void CleanUp() {  }; //Empty, for now

	void Pause() {}; //Emptyyyyyy
	void Resume() {}; //Same here

	void HandleEvents(Game*) {} // Nothing to see here
	void Update(Game*, sf::RenderWindow*);
	void Render(Game*, sf::RenderWindow*);

	static PlayState* Instance() { return &instance; }

private:
	static PlayState instance;
};

