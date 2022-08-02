#include "RangeSlider.h"

#include "Utils.h"


RangeSlider::RangeSlider(const sf::Vector2f& pos, const sf::Vector2f& size, int min, int max, int value)
	: m_size(size), m_min(min), m_max(max), m_value(value)
{
	m_sliderTex = new sf::Texture();

	if(!m_sliderTex->loadFromFile("assets/slider.png"))
		Utils::FatalError(TEXT("Failed to load slider texture."));

	//Setup the rendering components
	m_slideBar.setFillColor(sf::Color(102, 102, 102));
	m_slideBar.setOutlineColor(sf::Color(77, 76, 76));

	m_slider.setTexture(m_sliderTex, true); // test this bool param pls **TODO**

	//Apply all the default transforms
	Resize(size); // Apply resizing first since size is needed to do position calculations
	Move(pos);
}

RangeSlider::~RangeSlider()
{
	delete m_sliderTex;
}

void RangeSlider::Move(const sf::Vector2f& pos)
{
	float barY = pos.y + m_slideBar.getSize().y * 2;
	m_slideBar.setPosition(sf::Vector2f(pos.x, barY));

	float slideX = pos.x + (m_slider.getSize().x + m_slideBar.getSize().x) / 2; // Change that to fit the values
	m_slider.move(sf::Vector2f(slideX, pos.y));
}

void RangeSlider::Resize(const sf::Vector2f& size)
{
	m_slideBar.setSize(sf::Vector2f(size.x, size.y / 5));
	m_slider.setSize(sf::Vector2f(size.x / 6, size.y));
}

void RangeSlider::Update()
{
	//TODO: Actual input and cursor following + click detection all that shit
}

void RangeSlider::Render(sf::RenderWindow* window)
{
	window->draw(m_slideBar);
	window->draw(m_slider);
}