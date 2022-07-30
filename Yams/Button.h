#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
private:
	sf::Text m_text;
	sf::RectangleShape m_rect;
	std::function<void()> m_onClick;

	sf::Vector2f m_position;

	sf::Color m_fillColor;
	sf::Color m_clickColor;
	sf::Color m_hoverColor;

	bool m_hovered = false;
	bool m_clicked = false;

	//Fix spam when click maintained
	bool m_triggered = false;
public:
	Button() {}
	Button(const sf::Text& text, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Color& clickColor, const sf::Color& hoverColor, std::function<void()> clickEvent);
	//~Button();

	void Move(const sf::Vector2f pos);

	inline void SetFillColor(const sf::Color& fillColor) { m_fillColor = fillColor; }
	inline void SetClickColor(const sf::Color& clickColor) { m_clickColor = clickColor; }
	inline void SetHoverColor(const sf::Color& hoverColor) { m_hoverColor = hoverColor; }
	inline void OnClick(std::function<void()> action) { m_onClick = action; }

	void Update(const sf::Vector2i& mousePos);
	void Render(sf::RenderWindow* window);

};

