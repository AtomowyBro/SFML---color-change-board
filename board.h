#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "field.h"

const int Wys_planszy = 10;
const int Sze_planszy = 10;

class board
{
	field tablica[Wys_planszy][Sze_planszy]; // tablica klas field
public:
	board(); // 
	void drawboard(sf::RenderWindow & win); //?
	void deploy_mines(int n, bool random);
	bool hasMine(int x, int y);
	int count_mines(int x, int y);
	void odkryj(int x, int y);
	bool iscovered(int x, int y);
	bool isflage(int x, int y);
	void change_flage(int x, int y);
};