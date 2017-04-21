#include "menu.h"


main_window::main_window()
{
	button1.text_change("Graj");
	button1.setpos(200, 100);
	poziom[0].setpos(100, 150);
	poziom[1].setpos(200, 150);
	poziom[2].setpos(300, 150);
}

void main_window::draw(sf::RenderWindow & win)
{

	for (int i = 0;i < 3;i++)
	{
		poziom[i].draw(win);
		if (poziom[i].is_active())
			poziom[i].color_active();
		else
			poziom[i].color_inactive();
	}
	button1.color_inactive();
	
	button1.draw(win);
}

void main_window::change_active(int i)
{
	poziom[i].change_active();
}

void main_window::to_inactive(int i,int j)
{
	poziom[i].to_inactive();
	poziom[j].to_inactive();
}

void main_window::text_change(std::string text)
{
	button1.text_change(text);
}