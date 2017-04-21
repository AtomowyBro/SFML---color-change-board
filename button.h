#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class button
{
	sf::RectangleShape pbutton;
	bool isactive;
	sf::Color button_color;
	sf::Color button_color_pressed;
	sf::String button_name; //nie wyswietla poniewaz nie ma funkcji draw!!!
	sf::Font button_font;
	sf::Text button_text;
	int Font_size;
public:
	button();
	bool is_active();
	void to_inactive();
	void setpos(int x, int y);
	void color_inactive();
	void color_active();
	void button::change_active();
	void text_change(std::string text);
	void draw(sf::RenderWindow & win);
};