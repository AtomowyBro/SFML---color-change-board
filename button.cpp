#include "button.h"

button::button()
{
	isactive = false;
	Font_size = 35;
	button_font.loadFromFile("arial.ttf");
	pbutton.setSize(sf::Vector2f(80, 40));
	button_color = sf::Color (126,126,126);
	button_color_pressed = sf::Color(192, 192, 192);
	button_text.setFont(button_font);
	button_text.setPosition(10, 10);
	button_text.setString(button_name);
	button_text.setFillColor(sf::Color::Black);
	button_text.setCharacterSize(20);
}

void button::setpos(int x, int y)
{
	pbutton.setPosition(x, y);
}

void button::text_change(std::string text)
{
	button_name = text;
}

void button::color_inactive()
{
	pbutton.setFillColor(button_color);
}

void button::color_active()
{
	pbutton.setFillColor(button_color_pressed);
}

void button::change_active()
{
	if (isactive)
		isactive = false;
	else
		isactive = true;
}

void button::to_inactive() 
{
	isactive = false;
}

bool button::is_active()
{
	return isactive;
}

void button::draw(sf::RenderWindow & win)
{
	//win.draw(button_name);
	win.draw(pbutton);
}