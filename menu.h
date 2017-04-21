#include<SFML/Graphics.hpp>
#include"button.h"

class main_window
{
	button button1;
	button poziom[3];
public:
	main_window();
	void change_active(int i);
	void to_inactive(int i, int j);
	void text_change(std::string text);
	void draw(sf::RenderWindow & win);
};