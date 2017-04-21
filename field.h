#pragma once
#include<SFML/Graphics.hpp>

const int Wys_pola = 20;
const int Sze_pola = 20;

class field
{
	bool bmine;
	bool bcovered;
	sf::Color covered, flage, uncovered, mine, uncovered_near; //dwa kolory dla odkrytego i zakrytego
	bool bflage; // zamiana koloru
	sf::RectangleShape pole; // prostokat o nazwie pole

public:
	field()
	{
		covered = sf::Color::Green; //zakryte ma kolor czarny 
		flage = sf::Color::Blue; //odkryte kolor niebieski
		uncovered = sf::Color::White;
		mine = sf::Color::Red;
		uncovered_near = sf::Color::Transparent;
		bflage = false; // domyslnie zakryte
		pole.setSize(sf::Vector2f(Wys_pola, Sze_pola)); //rozmiary prostakata 
		bmine = false;
		bcovered = true;
	}
	void change_flage(); // zmiana bcovered => zmiana koloru
	void setpos(int x, int y); // ustawienie pozycji pola
	void color_covered();
	void color_flage();
	void color_uncovered();
	void color_mine();
	void color_uncovered_near();
	bool isflage();
	bool iscovered();
	bool ismine();
	void place_mine();
	void uncover();
	void drawfield(sf::RenderWindow & win); // ?
};