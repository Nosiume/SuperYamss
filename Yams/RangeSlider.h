#pragma once

#include <SFML/Graphics.hpp>

class RangeSlider
{
private:
	//Texture size is (50, 75)
	sf::Texture* m_sliderTex = nullptr;

	sf::RectangleShape m_slideBar;
	sf::RectangleShape m_slider;

	sf::Vector2f m_barPos;
	sf::Vector2f m_sliderPos;

	sf::Vector2f m_size;

	int m_min = 0, m_max = 100;
	int m_value = 50;

public:
	RangeSlider() {} // Avoid bugs but generally pls use the full constructor
	RangeSlider(const sf::Vector2f& pos, const sf::Vector2f& size = sf::Vector2f(300, 75), int min = 0, int max = 100, int value = 50);
	~RangeSlider();

	void Move(const sf::Vector2f& pos);
	void Resize(const sf::Vector2f& size);

	void Update();
	void Render(sf::RenderWindow* window);

	inline int GetValue() const { return m_value; }
};

