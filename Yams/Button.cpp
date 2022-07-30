#include "Button.h"

Button::Button(
	const sf::Text& text, 
	const sf::Vector2f& dimensions,
	const sf::Color& fillColor,
	const sf::Color& clickColor, 
	const sf::Color& hoverColor, 
	std::function<void()> clickEvent)
	//Defines everything inside the class from constructor
	: m_text(text), m_fillColor(fillColor), m_clickColor(clickColor), m_hoverColor(hoverColor), m_onClick(clickEvent)
{
	m_rect = sf::RectangleShape(dimensions);
}

void Button::Update(const sf::Vector2i& mousePos)
{
	m_hovered = m_rect.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y));
	m_clicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (m_clicked && m_hovered && !m_triggered) {
		m_onClick(); //call event
		m_triggered = true;
	} else if (!m_clicked && m_triggered)
		m_triggered = false;
}

void Button::Render(sf::RenderWindow* window)
{
	if (m_clicked && m_hovered)
		m_rect.setFillColor(m_clickColor);
	else if (m_hovered)
		m_rect.setFillColor(m_hoverColor);
	else
		m_rect.setFillColor(m_fillColor);

	window->draw(m_rect);
	window->draw(m_text);
}

void Button::Move(const sf::Vector2f pos)
{
	m_position = pos;

	//Adjust text to be in center of rectangle
	sf::FloatRect textBounds = m_text.getGlobalBounds();
	sf::FloatRect rectBounds = m_rect.getGlobalBounds();
	float x = (rectBounds.width - textBounds.width) / 2 + m_position.x;
	float y = (rectBounds.height - textBounds.height - 5) / 2 + m_position.y;

	m_text.move(sf::Vector2f(x, y));
	m_rect.move(pos);
}